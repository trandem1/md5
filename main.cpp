/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: trandem
 *
 * Created on April 3, 2018, 9:40 PM
 */

#include <iostream>
#include <hashlib++/hashlibpp.h>
#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <csignal>
#include<mpi.h>
#define RESULT 60
#define DATA 40
using namespace std;

/*
 * 
 */
string getmd5hash(string ml) {
    hashwrapper *h = new md5wrapper();
    string md5 = h->getHashFromString(ml);
    delete h;
    return md5;
}

const string pass = "abcdefghijknmltropqvwxysuz";

string generate_pass(string startpass, string endpass, string pass_find) {
     clock_t tStart = clock();
    string pass_bingo = "";
    int maxindex = pass.length() - 1;
    string copy = startpass;
    while (copy != endpass) {
        for (int i = copy.length() - 1; i >= 0; i--) {
            int position = pass.find(copy[i]);
            if (position == maxindex) {
                copy[i] = 'a';
                copy[i - 1] = pass[pass.find(copy[i - 1])];
                continue;
            } else {
                copy[i] = pass[position + 1];
                break;
            }
        }
        if (getmd5hash(copy) == pass_find) {
            pass_bingo = copy;
            cout << "find it\n";
            cout<<+"\n"+pass_bingo+"\n";
            printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
            break;
        }
    }
    return pass_bingo;
}

int ranki(string start,string end,string passfind) {
    generate_pass(start, end, getmd5hash(passfind));
    return 0;
}


int main(int argc, char** argv) {
    int rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0) {
         ranki("aaaaa","gzzzz","aaada");
    } else if (rank ==1) {
       ranki("haaaa","mzzzz","aaada");
    }else if(rank ==3){
        ranki("laaaa","qzzzz","aaada");
    }else if(rank ==4){
        ranki("vaaaa","zzzzz","aaada");
    }

    MPI_Finalize();
    return 0;
}
