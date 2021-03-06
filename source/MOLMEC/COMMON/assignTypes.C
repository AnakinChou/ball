// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: assignTypes.C,v 1.15 2004/12/17 15:29:37 amoll Exp $

#include <BALL/MOLMEC/COMMON/assignTypes.h>

#include <iostream>

#include <BALL/SYSTEM/path.h>
#include <BALL/KERNEL/fragment.h>

using namespace std;

namespace BALL 
{

	AssignBaseProcessor::AssignBaseProcessor()
		: UnaryProcessor<Atom>(),
			unassigned_atoms_(),
			max_number_unassigned_atoms_()
	{
	}

	void AssignBaseProcessor::setMaximumUnassignedAtoms(Size nr)
	{
		max_number_unassigned_atoms_ = nr;
	}
	
	Size AssignBaseProcessor::getMaximumUnassignedAtoms() const
	{
		return max_number_unassigned_atoms_;
	}

	Size AssignBaseProcessor::getNumberOfUnassignedAtoms() const
	{
		return unassigned_atoms_.size();
	}

	HashSet<const Atom*>& AssignBaseProcessor::getUnassignedAtoms()
	{
		return unassigned_atoms_;
	}


	AssignTypeNameProcessor::AssignTypeNameProcessor(const String& filename, bool overwrite)
		:	overwrite_(overwrite)
	{
		Path path;
		String filepath = path.find(filename);
		if (filepath == "")
		{
			throw Exception::FileNotFound(__FILE__, __LINE__, filename);
		}
		ifstream	type_file(filepath.c_str());

		String line;
		String type;
		String name;

		while (type_file)
		{
			line.getline(type_file);
			
			name = line.getField(0);
			type = line.getField(1);
			
			type_map_[name] = type;
		}

		type_file.close();
	}

	Processor::Result	AssignTypeNameProcessor::operator () (Atom& atom)
	{
		// if the atom type shall be overwritten or the type is not yet assigned: assign it
		if (overwrite_ || atom.getTypeName() == BALL_ATOM_DEFAULT_TYPE_NAME)
		{
			// retrieve the full atom name
			String name  = atom.getFullName();
				
			// if this name is in the hash map, assign it
			if (type_map_.has(name))
			{
				atom.setTypeName(type_map_[name]);
			} 
			else 
			{
				// try to match the full name without variant extensions (-xxx)
				name = atom.getFullName(Atom::NO_VARIANT_EXTENSIONS);
				if (type_map_.has(name)) 
				{
					atom.setTypeName(type_map_[name]);				
				}
				else 
				{
					// last, not least: try wildcard matching for the residue
					name = "*:" + atom.getName();
					if (type_map_.has(name))
					{
						atom.setTypeName(type_map_[name]);				
					} 
					else 
					{	
						// we could not assign a type name - complain!
						Log.warn() << "AssignTypeNameProcessor: could not assign type name for atom " 
											 << atom.getFullName(Atom::NO_VARIANT_EXTENSIONS) << endl;
						unassigned_atoms_.insert(&atom);
						if (unassigned_atoms_.size() > max_number_unassigned_atoms_) return Processor::ABORT;
					}
				}
			}
		}

		return Processor::CONTINUE;
	}

	AssignTypeProcessor::AssignTypeProcessor(const AtomTypes& atom_types)
	{
		atom_types_ = atom_types;
	}

	Processor::Result	AssignTypeProcessor::operator () (Atom& atom)
	{
		Atom::Type type = atom_types_.getType(atom.getTypeName());
		if (type == Atom::UNKNOWN_TYPE)
		{
			Log.warn() << "AssignTypeProcessor: could not assign atom type for " << atom.getTypeName() << endl;
			unassigned_atoms_.insert(&atom);
			if (unassigned_atoms_.size() > max_number_unassigned_atoms_) return Processor::ABORT;
		} 
		else 
		{
			atom.setType(type);
		}

		return Processor::CONTINUE;
	}

} // namespace BALL
