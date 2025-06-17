cmake_minimum_required(VERSION 3.15)
                                             
project(Tests                       
            DESCRIPTION "Testes Biblioteca"
            LANGUAGES C
            )

add_executable(test teste_gauss_eliminacao.c unity/unity.c)


#linkando biblioteca matematica
find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
    target_link_libraries(test PUBLIC ${MATH_LIBRARY})
endif()