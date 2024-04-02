cmake_minimum_required(VERSION 3.26)
project(Primer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Primer main.cpp
        obj/MultiQuery/QueryResult.h
        obj/MultiQuery/TextQuery.h
        obj/MultiQuery/Query_base.h
        obj/MultiQuery/WordQuery.h
        obj/MultiQuery/NoQuery.h
        obj/MultiQuery/AndQuery.h
        obj/MultiQuery/OrQuery.h
        obj/MultiQuery/Query.h
        obj/MultiQuery/BinaryQuery.h
        obj/MultiQuery/TextQuery.cpp
)
