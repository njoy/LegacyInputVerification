
add_executable( lipservice.BROADR.Card2.Mat1.test Mat1.test.cpp )
target_compile_options( lipservice.BROADR.Card2.Mat1.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${lipservice_appended_flags} )
target_link_libraries( lipservice.BROADR.Card2.Mat1.test PUBLIC lipservice ) 
add_test( NAME lipservice.BROADR.Card2.Mat1 COMMAND lipservice.BROADR.Card2.Mat1.test )