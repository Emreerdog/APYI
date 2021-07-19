file(GLOB_RECURSE APYI_CONFIGURATOR_SOURCE ./AdvancedPythonInterface/Configurator/*.cpp)
file(GLOB_RECURSE APYI_CONFIGURATOR_HEADER ./AdvancedPythonInterface/Configurator/*.h)

file(GLOB_RECURSE APYI_DATE_SOURCE ./AdvancedPythonInterface/Date/*.cpp)
file(GLOB_RECURSE APYI_DATE_HEADER ./AdvancedPythonInterface/Date/*.h)

file(GLOB_RECURSE APYI_FILESYSTEM_SOURCE ./AdvancedPythonInterface/FileSystem/*.cpp)
file(GLOB_RECURSE APYI_FILESYSTEM_HEADER ./AdvancedPythonInterface/FileSystem/*.h)

file(GLOB_RECURSE APYI_IMPORTER_SOURCE ./AdvancedPythonInterface/Importer/*.cpp)
file(GLOB_RECURSE APYI_IMPORTER_HEADER ./AdvancedPythonInterface/Importer/*.h)

file(GLOB_RECURSE APYI_LOGGING_SOURCE ./AdvancedPythonInterface/Logging/*.cpp)
file(GLOB_RECURSE APYI_LOGGING_HEADER ./AdvancedPythonInterface/Logging/*.h)

file(GLOB_RECURSE APYI_OBJECTRESOURCE_SOURCE ./AdvancedPythonInterface/ObjectResource/*.cpp)
file(GLOB_RECURSE APYI_OBJECTRESOURCE_HEADER ./AdvancedPythonInterface/ObjectResource/*.h)

file(GLOB_RECURSE APYI_OBJECTUTILS_SOURCE ./AdvancedPythonInterface/ObjectUtils/*.cpp)
file(GLOB_RECURSE APYI_OBJECTUTILS_HEADER ./AdvancedPythonInterface/ObjectUtils/*.h)

file(GLOB_RECURSE APYI_PATTERNOPS_SOURCE ./AdvancedPythonInterface/PatternOps/*.cpp)
file(GLOB_RECURSE APYI_PATTERNOPS_HEADER ./AdvancedPythonInterface/PatternOps/*.h)

file(GLOB_RECURSE APYI_PYTYPES_SOURCE ./AdvancedPythonInterface/PyTypes/*.cpp)
file(GLOB_RECURSE APYI_PYTYPES_HEADER ./AdvancedPythonInterface/PyTypes/*.h)

add_library(apyi STATIC
        ${APYI_CONFIGURATOR_SOURCE}
        ${APYI_CONFIGURATOR_HEADER}
        ${APYI_DATE_SOURCE}
        ${APYI_DATE_HEADER}
        ${APYI_FILESYSTEM_SOURCE}
        ${APYI_FILESYSTEM_HEADER}
        ${APYI_IMPORTER_SOURCE}
        ${APYI_IMPORTER_HEADER}
        ${APYI_LOGGING_SOURCE}
        ${APYI_LOGGING_HEADER}
        ${APYI_OBJECTRESOURCE_SOURCE}
        ${APYI_OBJECTRESOURCE_HEADER}
        ${APYI_OBJECTUTILS_SOURCE}
        ${APYI_OBJECTUTILS_HEADER}
        ${APYI_PATTERNOPS_SOURCE}
        ${APYI_PATTERNOPS_HEADER}
        ${APYI_PYTYPES_SOURCE}
        ${APYI_PYTYPES_HEADER}
        )