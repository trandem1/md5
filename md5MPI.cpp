/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   md5MPI.cpp
 * Author: trandem
 *
 * Created on April 4, 2018, 9:37 AM
 */

#include <hashlib++/hashlibpp.h>

#include <iostream>

#include <cstdlib>

#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
 * 
 */
//const string pass = "abcd";
//
//string getmd5hash(string ml) {
//    hashwrapper *h = new md5wrapper();
//    string md5 = h->getHashFromString(ml);
//    delete h;
//    return md5;
//}
//string generate_pass(string startpass, string endpass, string pass_find) {
//    string pass_bingo = "";
//    int maxindex = pass.length() - 1;
//    string copy = startpass;
//    while (copy != endpass) {
//        for (int i = copy.length() - 1; i >= 0; i--) {
//            int position = pass.find(copy[i]);
//            if (position == maxindex) {
//                copy[i] = 'a';
//                copy[i - 1] = pass[pass.find(copy[i - 1])];
//                continue;
//            } else {
//                copy[i] = pass[position + 1];
//                break;
//            }
//        }
//        if (copy == pass_find) {
//            pass_bingo = copy;
//            cout << "find it\n";
//            break;
//        }
//    }
//    return pass_bingo;
//}
//
//int rank0(int len_pass) {
//    int np;
//    char pass[len_pass];
//    string passrs;
//    MPI_Status status;
//    MPI_Comm_size(MPI_COMM_WORLD, &np);
//
//
//    for (int i = 1; i < np; i++) {
//        MPI_Recv(pass, len_pass, MPI_CHAR, i, RESULT, MPI_COMM_WORLD, &status);
//        for (int i = 0; i < len_pass; i++) {
//            passrs += pass[i];
//        }
//    }
//    cout << passrs;
//    return 0;
//}
//
//int ranki() {
//
//    string t = generate_pass("aaaa", "adaa", getmd5hash("aada"));
//    MPI_Send(t.c_str(), t.length(), MPI_CHAR, 0, RESULT, MPI_COMM_WORLD);
//    return 0;
//}
//
//int main(int argc, char** argv) {
//    int rank;
//    MPI_Init(&argc, &argv);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    if (rank == 0) {
//        rank0(4);
//    } else {
//        ranki();
//    }
//    MPI_Finalize();
//    return 0;
//}
