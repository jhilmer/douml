TEMPLATE    = app
TARGET        = irose
CONFIG -= app_bundle
CONFIG        += warn_on qt c++11
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES        += WITHCPP WITHJAVA WITHIDL  WITHPHP WITHPYTHON TRUE=true FALSE=false
HEADERS        = ./UmlDeploymentView.h \
          ./UmlTypeSpec.h \
          ./UmlBaseArtifact.h \
          ./UmlBaseNcRelation.h \
          ./OnInstanceCmd.h \
          ./UmlClassItem.h \
          ./UmlUseCaseDiagram.h \
          ./UmlBaseUseCaseView.h \
          ./UmlArtifact.h \
          ./UmlActualParameter.h \
          ./UmlSettings.h \
          ./UmlBaseDiagram.h \
          ./UmlBaseUseCaseDiagram.h \
          ./anItemKind.h \
          ./UmlBaseClassView.h \
          ./JavaSettings.h \
          ./UmlBaseDeploymentDiagram.h \
          ./UmlCollaborationDiagram.h \
          ./UmlNode.h \
          ./IdlSettings.h \
          ./UmlDeploymentDiagram.h \
          ./UmlBaseOperation.h \
          ./JavaSettingsCmd.h \
          ./Uc.h \
          ./UmlNcRelation.h \
          ./aVisibility.h \
          ./UmlBaseClassItem.h \
          ./UmlBaseExtraClassMember.h \
          ./UmlSequenceDiagram.h \
          ./CppSettingsCmd.h \
          ./UmlUseCaseView.h \
          ./IdlSettingsCmd.h \
          ./UmlBaseItem.h \
          ./UmlBaseComponentView.h \
          ./CppSettings.h \
          ./UmlBaseComponent.h \
          ./UmlClassView.h \
          ./MiscGlobalCmd.h \
          ./File.h \
          ./UmlBaseDeployment.h \
          ./UmlClassDiagram.h \
          ./aDirection.h \
          ./CmdFamily.h \
          ./UmlFormalParameter.h \
          ./UmlBaseClass.h \
          ./UmlItem.h \
          ./UmlCom.h \
          ./UmlUseCase.h \
          ./aRelationKind.h \
          ./UmlOperation.h \
          ./PackageGlobalCmd.h \
          ./UmlPackage.h \
          ./UmlComponentView.h \
          ./UmlClassMember.h \
          ./UmlBaseClassDiagram.h \
          ./ClassGlobalCmd.h \
          ./UmlBaseClassMember.h \
          ./UmlSettingsCmd.h \
          ./UmlClass.h \
          ./UmlBaseCollaborationDiagram.h \
          ./UmlBaseRelation.h \
          ./UmlBaseFormalParameter.h \
          ./UmlDiagram.h \
          ./UmlRelation.h \
          ./UmlBaseComponentDiagram.h \
          ./UmlBaseUseCase.h \
          ./UmlComponentDiagram.h \
          ./UmlComponent.h \
          ./UmlBaseSequenceDiagram.h \
          ./Artifact.h \
          ./util.h \
          ./UmlBaseAttribute.h \
          ./UmlBasePackage.h \
          ./UmlBaseDeploymentView.h \
          ./UmlAttribute.h \
          ./UmlBaseNode.h \
          ./UmlExtraClassMember.h \
          ./UmlBaseActualParameter.h
SOURCES        = ./UmlDeploymentView.cpp \
          ./UmlTypeSpec.cpp \
          ./UmlBaseArtifact.cpp \
          ./UmlBaseNcRelation.cpp \
          ./OnInstanceCmd.cpp \
          ./UmlClassItem.cpp \
          ./UmlUseCaseDiagram.cpp \
          ./UmlBaseUseCaseView.cpp \
          ./UmlArtifact.cpp \
          ./UmlActualParameter.cpp \
          ./UmlSettings.cpp \
          ./UmlBaseDiagram.cpp \
          ./UmlBaseUseCaseDiagram.cpp \
          ./anItemKind.cpp \
          ./UmlBaseClassView.cpp \
          ./JavaSettings.cpp \
          ./UmlBaseDeploymentDiagram.cpp \
          ./UmlCollaborationDiagram.cpp \
          ./UmlNode.cpp \
          ./IdlSettings.cpp \
          ./Main.cpp \
          ./UmlDeploymentDiagram.cpp \
          ./UmlBaseOperation.cpp \
          ./JavaSettingsCmd.cpp \
          ./Uc.cpp \
          ./UmlNcRelation.cpp \
          ./aVisibility.cpp \
          ./UmlBaseClassItem.cpp \
          ./UmlBaseExtraClassMember.cpp \
          ./UmlSequenceDiagram.cpp \
          ./CppSettingsCmd.cpp \
          ./UmlUseCaseView.cpp \
          ./IdlSettingsCmd.cpp \
          ./UmlBaseItem.cpp \
          ./UmlBaseComponentView.cpp \
          ./CppSettings.cpp \
          ./UmlBaseComponent.cpp \
          ./UmlClassView.cpp \
          ./MiscGlobalCmd.cpp \
          ./File.cpp \
          ./UmlBaseDeployment.cpp \
          ./UmlClassDiagram.cpp \
          ./aDirection.cpp \
          ./CmdFamily.cpp \
          ./UmlFormalParameter.cpp \
          ./UmlBaseClass.cpp \
          ./UmlItem.cpp \
          ./UmlCom.cpp \
          ./UmlUseCase.cpp \
          ./aRelationKind.cpp \
          ./UmlOperation.cpp \
          ./PackageGlobalCmd.cpp \
          ./UmlPackage.cpp \
          ./UmlComponentView.cpp \
          ./UmlClassMember.cpp \
          ./UmlBaseClassDiagram.cpp \
          ./ClassGlobalCmd.cpp \
          ./UmlBaseClassMember.cpp \
          ./UmlSettingsCmd.cpp \
          ./UmlClass.cpp \
          ./UmlBaseCollaborationDiagram.cpp \
          ./UmlBaseRelation.cpp \
          ./UmlBaseFormalParameter.cpp \
          ./UmlDiagram.cpp \
          ./UmlRelation.cpp \
          ./UmlBaseComponentDiagram.cpp \
          ./UmlBaseUseCase.cpp \
          ./UmlComponentDiagram.cpp \
          ./UmlComponent.cpp \
          ./UmlBaseSequenceDiagram.cpp \
          ./Artifact.cpp \
          ./util.cpp \
          ./UmlBaseAttribute.cpp \
          ./UmlBasePackage.cpp \
          ./UmlBaseDeploymentView.cpp \
          ./UmlAttribute.cpp \
          ./UmlBaseNode.cpp \
          ./UmlExtraClassMember.cpp \
          ./UmlBaseActualParameter.cpp
#The following line was inserted by qt3to4
QT += network  widgets

INCLUDEPATH += ../../src
QT += testlib

    UI_DIR = src/ui
    DESTDIR = ../../bin

CONFIG(release, debug|release) {
    DEFINES += NDEBUG
    MOC_DIR = $${DESTDIR}/moc_release/$${TARGET}
    OBJECTS_DIR = $${DESTDIR}/obj_release/$${TARGET}
}

CONFIG(debug, debug|release) {
    DEFINES += TRACE DEBUG DEBUG_DOUML
    MOC_DIR = $${DESTDIR}/moc_debug/$${TARGET}
    OBJECTS_DIR = $${DESTDIR}/obj_debug/$${TARGET}
}
