##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=PECLBachillerVelaDavid
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/david/Desktop/PECLExtraordinaria
ProjectPath            :=C:/Users/david/Desktop/PECLExtraordinaria/PECLBachillerVelaDavid
IntermediateDirectory  :=../build-$(ConfigurationName)/PECLBachillerVelaDavid
OutDir                 :=../build-$(ConfigurationName)/PECLBachillerVelaDavid
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=david
Date                   :=08/06/2022
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/PECLBachillerVelaDavid/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/Pila.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoPila.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/Lista.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoLista.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/Paciente.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/Arbol.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/Cola.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoCola.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/Controlador.cpp$(ObjectSuffix) \
	../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoArbol.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/PECLBachillerVelaDavid/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\PECLBachillerVelaDavid" mkdir "..\build-$(ConfigurationName)\PECLBachillerVelaDavid"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\PECLBachillerVelaDavid" mkdir "..\build-$(ConfigurationName)\PECLBachillerVelaDavid"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/PECLBachillerVelaDavid/.d:
	@if not exist "..\build-$(ConfigurationName)\PECLBachillerVelaDavid" mkdir "..\build-$(ConfigurationName)\PECLBachillerVelaDavid"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/PECLBachillerVelaDavid/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/PECLBachillerVelaDavid/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/Desktop/PECLExtraordinaria/PECLBachillerVelaDavid/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/PECLBachillerVelaDavid/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/PECLBachillerVelaDavid/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/PECLBachillerVelaDavid/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/Pila.cpp$(ObjectSuffix): Pila.cpp ../build-$(ConfigurationName)/PECLBachillerVelaDavid/Pila.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/Desktop/PECLExtraordinaria/PECLBachillerVelaDavid/Pila.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Pila.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/PECLBachillerVelaDavid/Pila.cpp$(DependSuffix): Pila.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/PECLBachillerVelaDavid/Pila.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/PECLBachillerVelaDavid/Pila.cpp$(DependSuffix) -MM Pila.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/Pila.cpp$(PreprocessSuffix): Pila.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/Pila.cpp$(PreprocessSuffix) Pila.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoPila.cpp$(ObjectSuffix): NodoPila.cpp ../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoPila.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/Desktop/PECLExtraordinaria/PECLBachillerVelaDavid/NodoPila.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NodoPila.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoPila.cpp$(DependSuffix): NodoPila.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoPila.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoPila.cpp$(DependSuffix) -MM NodoPila.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoPila.cpp$(PreprocessSuffix): NodoPila.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoPila.cpp$(PreprocessSuffix) NodoPila.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/Lista.cpp$(ObjectSuffix): Lista.cpp ../build-$(ConfigurationName)/PECLBachillerVelaDavid/Lista.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/Desktop/PECLExtraordinaria/PECLBachillerVelaDavid/Lista.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lista.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/PECLBachillerVelaDavid/Lista.cpp$(DependSuffix): Lista.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/PECLBachillerVelaDavid/Lista.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/PECLBachillerVelaDavid/Lista.cpp$(DependSuffix) -MM Lista.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/Lista.cpp$(PreprocessSuffix): Lista.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/Lista.cpp$(PreprocessSuffix) Lista.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoLista.cpp$(ObjectSuffix): NodoLista.cpp ../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoLista.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/Desktop/PECLExtraordinaria/PECLBachillerVelaDavid/NodoLista.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NodoLista.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoLista.cpp$(DependSuffix): NodoLista.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoLista.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoLista.cpp$(DependSuffix) -MM NodoLista.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoLista.cpp$(PreprocessSuffix): NodoLista.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoLista.cpp$(PreprocessSuffix) NodoLista.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/Paciente.cpp$(ObjectSuffix): Paciente.cpp ../build-$(ConfigurationName)/PECLBachillerVelaDavid/Paciente.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/Desktop/PECLExtraordinaria/PECLBachillerVelaDavid/Paciente.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Paciente.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/PECLBachillerVelaDavid/Paciente.cpp$(DependSuffix): Paciente.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/PECLBachillerVelaDavid/Paciente.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/PECLBachillerVelaDavid/Paciente.cpp$(DependSuffix) -MM Paciente.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/Paciente.cpp$(PreprocessSuffix): Paciente.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/Paciente.cpp$(PreprocessSuffix) Paciente.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/Arbol.cpp$(ObjectSuffix): Arbol.cpp ../build-$(ConfigurationName)/PECLBachillerVelaDavid/Arbol.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/Desktop/PECLExtraordinaria/PECLBachillerVelaDavid/Arbol.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Arbol.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/PECLBachillerVelaDavid/Arbol.cpp$(DependSuffix): Arbol.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/PECLBachillerVelaDavid/Arbol.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/PECLBachillerVelaDavid/Arbol.cpp$(DependSuffix) -MM Arbol.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/Arbol.cpp$(PreprocessSuffix): Arbol.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/Arbol.cpp$(PreprocessSuffix) Arbol.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/Cola.cpp$(ObjectSuffix): Cola.cpp ../build-$(ConfigurationName)/PECLBachillerVelaDavid/Cola.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/Desktop/PECLExtraordinaria/PECLBachillerVelaDavid/Cola.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Cola.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/PECLBachillerVelaDavid/Cola.cpp$(DependSuffix): Cola.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/PECLBachillerVelaDavid/Cola.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/PECLBachillerVelaDavid/Cola.cpp$(DependSuffix) -MM Cola.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/Cola.cpp$(PreprocessSuffix): Cola.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/Cola.cpp$(PreprocessSuffix) Cola.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoCola.cpp$(ObjectSuffix): NodoCola.cpp ../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoCola.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/Desktop/PECLExtraordinaria/PECLBachillerVelaDavid/NodoCola.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NodoCola.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoCola.cpp$(DependSuffix): NodoCola.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoCola.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoCola.cpp$(DependSuffix) -MM NodoCola.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoCola.cpp$(PreprocessSuffix): NodoCola.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoCola.cpp$(PreprocessSuffix) NodoCola.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/Controlador.cpp$(ObjectSuffix): Controlador.cpp ../build-$(ConfigurationName)/PECLBachillerVelaDavid/Controlador.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/Desktop/PECLExtraordinaria/PECLBachillerVelaDavid/Controlador.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Controlador.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/PECLBachillerVelaDavid/Controlador.cpp$(DependSuffix): Controlador.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/PECLBachillerVelaDavid/Controlador.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/PECLBachillerVelaDavid/Controlador.cpp$(DependSuffix) -MM Controlador.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/Controlador.cpp$(PreprocessSuffix): Controlador.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/Controlador.cpp$(PreprocessSuffix) Controlador.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoArbol.cpp$(ObjectSuffix): NodoArbol.cpp ../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoArbol.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/Desktop/PECLExtraordinaria/PECLBachillerVelaDavid/NodoArbol.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NodoArbol.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoArbol.cpp$(DependSuffix): NodoArbol.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoArbol.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoArbol.cpp$(DependSuffix) -MM NodoArbol.cpp

../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoArbol.cpp$(PreprocessSuffix): NodoArbol.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/PECLBachillerVelaDavid/NodoArbol.cpp$(PreprocessSuffix) NodoArbol.cpp


-include ../build-$(ConfigurationName)/PECLBachillerVelaDavid//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


