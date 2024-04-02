#include "string"
#include "fstream"
#include "iostream"
#include "map"
#include "vector"
#include "./obj/MultiQuery/Query.h"
#include "./obj/MultiQuery/AndQuery.h"
#include "./obj/MultiQuery/OrQuery.h"
#include "./obj/MultiQuery/NoQuery.h"


using namespace std;

int main() {
    ifstream input(R"(D:\ClionProject\Primer\file\TextSample)");

    TextQuery tx(input);
//
//    Query q("debug");
//
//    print(q.eval(tx));

    Query andq = ~Query("object") & Query("or") | Query("debug.");
    cout << andq << endl;

    print(andq.eval(tx));
}





