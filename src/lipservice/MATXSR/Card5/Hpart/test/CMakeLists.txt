
add_executable( lipservice.MATXSR.Card5.Hpart.test Hpart.test.cpp )
target_compile_options( lipservice.MATXSR.Card5.Hpart.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${lipservice_appended_flags} )
target_link_libraries( lipservice.MATXSR.Card5.Hpart.test PUBLIC lipservice ) 
add_test( NAME lipservice.MATXSR.Card5.Hpart COMMAND lipservice.MATXSR.Card5.Hpart.test )