
add_executable( lipservice.argument.parser.test
                Required.test.cpp
                parser.test.cpp
                Discriminating.test.cpp
                Defaulted.test.cpp
                Base.test.cpp
                Optional.test.cpp )
target_compile_options( lipservice.argument.parser.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${lipservice_appended_flags} )
target_link_libraries( lipservice.argument.parser.test PUBLIC lipservice ) 
add_test( NAME lipservice.argument.parser COMMAND lipservice.argument.parser.test )