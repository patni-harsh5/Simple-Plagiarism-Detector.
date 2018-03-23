//
//  RabinKarp.h
//  Plagiarism_Project
//
//  Created by Angeline Alex on 11/25/16.
//  Copyright © 2016 Angeline Alex. All rights reserved.
//

#ifndef RabinKarp_h
#define RabinKarp_h
#include<iostream>
#include<string>
using namespace std;
const static int check_bit_for_hash=256;
static bool rk_flag=false;
static int k_count=0;
class RabinKarp{
public:

    void search(string text,string pattern, int q){
        int m=(unsigned)pattern.length();
        int n=(unsigned)text.length();

        int i,j;
        int check_pattern=0;
        int check_text=0;
        int hash_value=1;

        for(i=0;i<m-1;i++){
            hash_value=(check_bit_for_hash*hash_value)%q;
        }

        for(i=0;i<m;i++){
            check_pattern=(check_bit_for_hash*check_pattern+pattern[i])%q;
            check_text=(check_bit_for_hash*check_text+text[i])%q;
        }
        for(i=0;i<=n-m;i++){
            if(check_text==check_pattern){
                for(j=0;j<m;j++){
                    if(text[i+j]!=pattern[j]) {
                        break;
                    }
                }
                if(j==m){
                    rk_flag=true;
                    cout<<endl<<"Pattern match found!!"<<endl;
                    k_count++;
                    cout<<pattern;

                }

            }

            if(i<n-m){
                check_text = (check_bit_for_hash*(check_text - text[i]*hash_value) + text[i+m])%q;

                if(check_text < 0)
                    check_text = (check_text + q);
            }
        }

    }
    void checkRabinKarp(string s,string array[],int size,int q){
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
                search(t,p,q);
            }
        cout<<endl<<endl;
        if(rk_flag==true){
            cout<<"Source : "<<s<<endl;
            cout<<"===================="<<endl;
        }


        testfiles.close();

    }
    void Rabin_Karp(string files[]){
        ifstream testfiles,myfile;
        string fileline;
        string patternline,pattern,p,t;
        string array[10000],filename;
        //string files[]={"Computers_Tomorrow.txt","Computers_Today.txt","Computers_backthen.txt"};
        myfile.open("text.txt");
        int x=-1;

        while (getline (myfile,patternline,'.')) {
            ++x;
            array[x]=patternline;

        }

        cout<<"##############################################################RABIN KARP"<<"###################################"<<endl;
        for(int i=0;i<=10;i++){


            filename=files[i];
            testfiles.open(files[i].c_str());
            rk_flag=false;
            checkRabinKarp(filename,array,x,101);

            testfiles.close();

        }

        cout<<"Percentage of Plagerized content in the main document : "<<(((double)k_count)/7)*100<<" %"<<endl;
    }

};






#endif /* RabinKarp_h */
