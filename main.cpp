//
//  main.cpp
//  Plagiarism_Project
//
//  Created by Angeline Alex on 11/5/16.
//  Copyright © 2016 Angeline Alex. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <cmath>
#include "KMPheader.h"
#include "LCSSheader.h"
#include "RabinKarp.h"
using namespace std;

int main () {

    string files[]={"text1.txt","text2.txt","text3.txt", "text4.txt",
    "text5.txt","text6.txt","text7.txt","text8.txt","text9.txt","text10.txt","text11.txt","text12.txt","text13.txt","text14.txt","text15.txt","text16.txt","text17.txt","text18.txt","text19.txt","text20.txt"};


    //KMP
    KMPheader k;
    clock_t k1,k2;
    k1=clock();
    k.Kmp_func(files);
    k2=clock();
    cout<<"====================================================================="<<endl;
    cout<<"Total time taken by KMP: "<<(double)(k2-k1)/CLOCKS_PER_SEC<<" milliseconds"<<endl;
    cout<<"====================================================================="<<endl;
    cout<<endl<<endl;

    //RabinKarp
    clock_t r1,r2;
    RabinKarp r;
    r1=clock();
    r.Rabin_Karp(files);
    r2=clock();
    cout<<"====================================================================="<<endl;
    cout<<"Total time taken by RABIN-KARP: "<<(double)(r2-r1)/CLOCKS_PER_SEC<<" milliseconds"<<endl;
    cout<<"====================================================================="<<endl;
    cout<<endl<<endl;


    //LCSS
    LCSSheader l;
    clock_t l1,l2;
    l1=clock();
    l.LCSS_func(files);
    l2=clock();
    cout<<"====================================================================="<<endl;
    cout<<"Total time taken by LCSS: "<<(double)(l2-l1)/CLOCKS_PER_SEC<<" milliseconds"<<endl;
    cout<<"====================================================================="<<endl;
    cout<<endl<<endl;




//  cout<<"##############################################################Rabin Karp###################################"<<endl;


    cout<<"TIME COMPARISON:"<<endl;
    cout<<"-----------------"<<endl;
    cout<<"KMP       : "<<(double)(k2-k1)/(CLOCKS_PER_SEC*1000)<<" seconds"<<endl;
    cout<<"LCSS      : "<<(double)(l2-l1)/(CLOCKS_PER_SEC*1000)<<" seconds"<<endl;
    cout<<"RABIN-KARP: "<<(double)(r2-r1)/(CLOCKS_PER_SEC*1000)<<" seconds"<<endl;


    //========================RABIN KARP============================

    return 0;
}

