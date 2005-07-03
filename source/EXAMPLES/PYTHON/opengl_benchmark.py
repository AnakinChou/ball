m = MainControl.getInstance(0)
pm = m.getPrimitiveManager()
py = PyWidget.getInstance(0)
dp = DisplayProperties.getInstance(0)
fd = MolecularFileDialog.getInstance(0)
pm.setMultithreadingMode(0)

result = 0
nr_runs = 70

def clearRepresentations():
	nr = pm.getNumberOfRepresentations()
	rl = pm.getRepresentations()
	i = 0
	while i < nr:
		m.remove(rl[i])
		i = i + 1

def runTest(name, model):
	global result
	run = 0
	dp.selectModel(model)
	dp.apply()
	v = Vector3(13, 84, 41)
	l = Vector3(13, 84, -7)
	u = Vector3(0, -1, 0)
	s = Scene.getInstance(0).getStage()
	s.getCamera().setViewPoint(v)
	s.getCamera().setLookAtPosition(l)
	s.getCamera().setLookUpVector(v)
	sm = SceneMessage(SceneMessage.UPDATE_CAMERA)
	sm.setStage(s)
	m.sendMessage(sm)
	timer = Timer();
	timer.start();
	while run < nr_runs and not py.toAbortScript():
		run += 1
		v = v + Vector3(0,0,1)
		l = l + Vector3(0,0,1)
		s.getCamera().setViewPoint(v)
		sm = SceneMessage(SceneMessage.UPDATE_CAMERA)
		sm.setStage(s)
		m.sendMessage(sm)
	timer.stop()
	model_result = timer.getClockTime()
	clearRepresentations()
	print name+" "+str(model_result)+" seconds"
	result += model_result

clearRepresentations()
m.getPrimitiveManager().setMultithreadingMode(0)
dp.enableCreationForNewMolecules(0)
dp.setDrawingPrecision(DRAWING_PRECISION_HIGH)
dp.setSurfaceDrawingPrecision(6.5)
dp.selectMode(DRAWING_MODE_SOLID)
dp.selectColoringMethod(COLORING_ELEMENT)
dp.setTransparency(0)
fd.openFile(Path().find("structures/bpti.pdb"))

Scene.getInstance(0).setVisible(1)
LogView.getInstance(0).setVisible(0)
GeometricControl.getInstance(0).setVisible(0)
DatasetControl.getInstance(0).setVisible(0)
MolecularControl.getInstance(0).setVisible(0)
PyWidget.getInstance(0).setVisible(0)

MainControl.getInstance(0).resize(800, 600)
MainControl.getInstance(0).processEvents(5000)

runTest("Lines", 		MODEL_LINES)
runTest("VDW",   		MODEL_VDW)
runTest("BAS",   		MODEL_BALL_AND_STICK)
runTest("Cartoon", 	MODEL_CARTOON)
runTest("SES", 			MODEL_SE_SURFACE)

print "Result: "+str(result)+" seconds"
result /= nr_runs
result = 1 / result
#scale results to the graphics_benchmark.py script
result /= 5
print "Result: "+str(result)+" BALLView OpenGL stones"
m.getPrimitiveManager().setMultithreadingMode(1)
