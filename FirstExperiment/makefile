errorRecordFile=error.log
compiler=g++
dependencies=Hash.cpp Key.cpp KVpair.cpp Car.cpp Interface.cpp main.cpp
binaryFile=a.out
options= -std=c++11
defalutBuild=${compiler} ${options} ${dependencies}


${binaryFile}:${dependencies}
	${defalutBuild}

clean: 
	rm ${binaryFile}

record:
	${defalutBuild} 2>${errorRecordFile}

debug:
	${compiler} -g ${options} ${dependencies}
