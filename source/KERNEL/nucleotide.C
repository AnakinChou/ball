// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//

#include <BALL/KERNEL/nucleotide.h>

#include <BALL/KERNEL/nucleicAcid.h>
#include <BALL/COMMON/exception.h>

using namespace std;

namespace BALL 
{

	Nucleotide::Nucleotide()
		:	Fragment(),
			id_(BALL_NUCLEOTIDE_DEFAULT_ID),
			insertion_code_(BALL_NUCLEOTIDE_DEFAULT_INSERTION_CODE)
	{
	}
		
	Nucleotide::Nucleotide(const Nucleotide& nucleotide, bool deep)
		:	Fragment(nucleotide, deep),
			id_(nucleotide.id_),
			insertion_code_(nucleotide.insertion_code_)
	{
	}
		
	Nucleotide::Nucleotide(const String& name, const String& id, char insertion_code)
		:	Fragment(name),
			id_(id),
			insertion_code_(insertion_code)
	{
	}

	Nucleotide::~Nucleotide()
	{
		destroy();
	}

	void Nucleotide::clear()
	{
		Fragment::clear();
		id_ = BALL_NUCLEOTIDE_DEFAULT_ID;
		insertion_code_ = BALL_NUCLEOTIDE_DEFAULT_INSERTION_CODE;
	}
		
	void Nucleotide::destroy()
	{
		Fragment::destroy();
		id_ = BALL_NUCLEOTIDE_DEFAULT_ID;
		insertion_code_ = BALL_NUCLEOTIDE_DEFAULT_INSERTION_CODE;
	}

	void Nucleotide::persistentWrite(PersistenceManager& pm, const char* name) const
	{
		pm.writeObjectHeader(this, name);
			Fragment::persistentWrite(pm);
			pm.writePrimitive(id_, "id_");
			pm.writePrimitive(insertion_code_, "insertion_code_");
		pm.writeObjectTrailer(name);
	}

	void Nucleotide::persistentRead(PersistenceManager& pm)
	{
		pm.checkObjectHeader(RTTI::getStreamName<Fragment>());
			Fragment::persistentRead(pm);
		pm.checkObjectTrailer(0);

		pm.readPrimitive(id_, "id_");
		pm.readPrimitive(insertion_code_, "insertion_code_");
	}
		
	void Nucleotide::set(const Nucleotide& nucleotide, bool deep)
	{
		Fragment::set(nucleotide, deep);
		id_ = nucleotide.id_;
		insertion_code_ = nucleotide.insertion_code_;
	}
			
	Nucleotide& Nucleotide::operator = (const Nucleotide& nucleotide)
	{
		set(nucleotide);
		return *this;
	}

	void Nucleotide::get(Nucleotide& nucleotide, bool deep) const
	{
		nucleotide.set(*this, deep);
	}
			
	void Nucleotide::swap(Nucleotide& nucleotide)
	{
		Fragment::swap(nucleotide);

		id_.swap(nucleotide.id_);

		char temp_insertion_code = insertion_code_;
		insertion_code_ = nucleotide.insertion_code_;
		nucleotide.insertion_code_ = temp_insertion_code;
	}

	NucleicAcid* Nucleotide::getNucleicAcid()
	{
		NucleicAcid* nucleic_acid_ptr = 0;
		for (Composite::AncestorIterator ancestor_it = beginAncestor(); !ancestor_it.isEnd(); ++ancestor_it)
		{
			nucleic_acid_ptr = dynamic_cast<NucleicAcid*>(&*ancestor_it);
			if (nucleic_acid_ptr != 0)
			{
				break;
			}
		}

		return nucleic_acid_ptr;
	}

	const NucleicAcid* Nucleotide::getNucleicAcid() const
	{
		return (const_cast<Nucleotide*>(this)->getNucleicAcid());
	}

	void Nucleotide::setID(const String &id)
	{
		id_ = id;
	}

	const String &Nucleotide::getID() const
	{
		return id_;
	}

	void Nucleotide::setInsertionCode(char insertion_code)
	{
		// Is the insertion code a visible ASCII character
		if(insertion_code < 32 || insertion_code > 126) {
			throw Exception::InvalidArgument(__FILE__, __LINE__,
				"The specified insertion code is invalid. Only visible values "
				"and the space character ' ' are allowed."
			);
		}

		insertion_code_ = insertion_code;
	}

	void Nucleotide::unsetInsertionCode() {
		insertion_code_ = ' ';
	}

	char Nucleotide::getInsertionCode() const
	{
		return insertion_code_;
	}

	void Nucleotide::prepend(Atom& atom)
	{
		Composite::prependChild(atom);
	}

	void Nucleotide::append(Atom &atom)
	{
		Composite::appendChild(atom);
	}

	void Nucleotide::insert(Atom &atom)
	{
		append(atom);
	}

	void Nucleotide::insertBefore(Atom &atom, Composite& before)
	{
		before.Composite::insertBefore(atom);
	}

	void Nucleotide::insertAfter(Atom& atom, Composite &after)
	{
		after.Composite::insertAfter(atom);
	}

	bool Nucleotide::remove(Atom& atom)
	{
		return Composite::removeChild(atom);
	}

	void Nucleotide::spliceBefore(Nucleotide& nucleotide)
	{
		Composite::spliceBefore(nucleotide);
	}

	void Nucleotide::spliceAfter(Nucleotide& nucleotide)
	{
		Composite::spliceAfter(nucleotide);
	}

	void Nucleotide::splice(Nucleotide& nucleotide)
	{
		Composite::splice(nucleotide);
	}

	bool Nucleotide::isTerminal() const
	{
		const NucleicAcid* parent = (*this).getNucleicAcid();
		if (parent != 0)
		{
			if (parent->get3Prime() == this ||
					parent->get5Prime() == this)
			{
				return true;
			}
		}
		return false;
	}

	bool Nucleotide::is5Prime() const
	{
		const NucleicAcid* parent = getNucleicAcid();
		if (parent != 0)
		{
			if (parent->get5Prime() == this)
			{
				return true;
			}
		}
		return false;
	}
		
	bool Nucleotide::is3Prime() const
	{
		const NucleicAcid* parent = getNucleicAcid();
		if (parent != 0)
		{
			if (parent->get3Prime() == this)
			{
				return true;
			}
		}
		return false;
	}

	bool Nucleotide::isValid() const
	{ 
		return (Fragment::isValid() && id_.isValid());
	}

	void Nucleotide::dump(ostream& s, Size depth) const
	{
		BALL_DUMP_STREAM_PREFIX(s);
		
		Fragment::dump(s, depth);
		
		BALL_DUMP_DEPTH(s, depth);
		s << "  id: " << id_ << endl;

		BALL_DUMP_DEPTH(s, depth);
		s << "  insertion code: " << insertion_code_ << endl;

		BALL_DUMP_STREAM_SUFFIX(s);
	}

	bool Nucleotide::operator == (const Nucleotide& nucleotide) const
	{
		return(Object::operator == (nucleotide));
	}

	bool Nucleotide::operator != (const Nucleotide& nucleotide) const
	{
		return ! (*this == nucleotide);
	}

} // namespace BALL
