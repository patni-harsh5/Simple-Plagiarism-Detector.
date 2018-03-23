//
//  KMPheader.h
//  Plagiarism_Project
//
//  Created by Angeline Alex on 11/25/16.
//  Copyright © 2016 Angeline Alex. All rights reserved.
//

#ifndef KMPheader_h
#define KMPheader_h
#include<iostream>
#include<string>
#include <fstream>
using namespace std;
static bool kmpflag=false;
static int p_count=0;
static int m_count=0;
class KMPheader{
public:


    void calculateKMPPrefix(string pattern, int calVal[])

    {
        int x = (unsigned)pattern.length(), j;
        calVal[0] = -1;
        for (int i = 1; i < x; i++)
        {
            j = calVal[i - 1];
            while (j >= 0)
            {
                if (pattern[j] == pattern[i - 1])
                    break;
                else
                    j = calVal[j];
            }
            calVal[i] = j + 1;
        }
    }

    bool KMP(string pattern, string text)
    {
        int m = (unsigned)pattern.length();
        int n = (unsigned)text.length();
        int calVal[m];

        calculateKMPPrefix(pattern, calVal);
        int i = 0;
        int j = 0;

        while (i < n)
        {
            if (j == -1)
            {
                i++;
                j = 0;
            }
            else if (text[i] == pattern[j])
            {
                i++;
                j++;
                if (j == m)
                    return 1;
            }
            else
                j = calVal[j];
        }
        return 0;
    }


      void createString(string s,string array[],int size){
        ifstream testfiles;

        string *str=new string[1000],fileline;
        string t,p;
        int x=-1;
        testfiles.open(s.c_str());

        while (getline(testfiles,fileline,'.')) {
            ++x;
            str[x]=fileline;
                }


        for(int i=0;i<=size;i++)
            for(int j=0;j<=x;j++){
                p=array[i];
                t=str[j];
                if(KMP(p,t)){
                    kmpflag=true;
                    cout<<"PLAGIARIZED CONTENT FOUND!!!"<<endl<<p<<endl;
                    p_count++;
                    cout<<endl;
                }
            }

        cout<<endl<<endl;

        testfiles.close();

    }

    void Kmp_func(string files[]){

        ifstream testfiles,myfile;
        string fileline;
        string patternline,pattern,p,t;
        string array[10000],s;
        //string files[]={"Computers_Tomorrow.txt","Computers_Today.txt","Computers_backthen.txt"};
        myfile.open("text.txt");
        int x=-1;
        while (getline (myfile,patternline,'.')) {
            ++x;
            array[x]=patternline;

        }

       cout<<"##############################################################KMP"
        <<"#################################################"<<endl;
        for(int i=0;i<=10;i++){

            s=files[i];
            testfiles.open(files[i].c_str());
            kmpflag=false;
            createString(s,array,x);
            if(kmpflag==true){
                cout<<"Source : "<<s<<endl<<endl;
                cout<<"===================="<<endl<<endl;
            }
            //cout<<"================================"<<endl<<endl;

        }
        //cout<<"P_count : "<<p_count<<endl;
        cout<<"Percentage of Plagerized content in the main document : "<<(((double)p_count)/7)*100<<" %"<<endl;
            testfiles.close();
            myfile.close();

    }
};

#endif /* KMPheader_h */
