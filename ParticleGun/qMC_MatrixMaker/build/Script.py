file=open("Run.mac","w")

file.write("/run/initialize\n")

for i in range (5,20001,5):
	file.write("/gun/energy "+str(i)+" keV\n/gun/particle neutron\n/run/beamOn 1000\n")

for i in range (5,20001,5):
        file.write("/gun/energy "+str(i)+" keV\n/gun/particle gamma\n/run/beamOn 1000\n")

file.close()

