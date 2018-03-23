//
//  LCSSheader.h
//  Plagiarism_Project
//
//  Created by Angeline Alex on 11/25/16.
//  Copyright © 2016 Angeline Alex. All rights reserved.
//

#ifndef LCSSheader_h
#define LCSSheader_h
#include<iostream>
#include<string>
using namespace std;
static bool flag=false;
static int lcs_count=0;
class LCSSheader{
public:
    void lcs(string pattern,string text)
    {
        string calculate_substr, max;

        for (int i=0; i < pattern.length(); i++)
            for (int j=0; j < text.length(); j++)
                for (int k=1; k <= pattern.length() && k <= text.length(); k++){
                    if (pattern.substr(i,k) == text.substr(j,k)){
                        calculate_substr = pattern.substr(i,k);
                    }
                    else{
                        if (calculate_substr.length() > max.length())
                            max=calculate_substr;
                        calculate_substr="";
                    }
                }
        if (calculate_substr.length() > max.length())
            max=calculate_substr;
        calculate_substr="";
        flag=true;
        cout << "PLAGIARIZED CONTENT FOUND using LCSS: " << max << endl;
        lcs_count++;
    }

    void checkLcss(string s,string array[],int size){
        ifstream testfiles;
        string *str=new string[1000],fileline;
        string t,p;
        int x=-1;
        testfiles.open(s.c_str());

        while (getline(testfiles,fileline,'\n')) {
            ++x;
            str[x]=fileline;
        }

        for(int i=0;i<=size;i++)
            for(int j=0;j<=x;j++){
                p=array[i];
                t=str[j];
                lcs(p,t);
            }


        cout<<endl<<endl;

        testfiles.close();
    }

    void LCSS_func(string files[]){
        ifstream testfiles,myfile;
        string fileline;
        string patternline,pattern,p,t;
        string array[10000],s;
        //string files[]={"Computers_Tomorrow.txt","Computers_Today.txt","Computers_backthen.txt"};
        myfile.open("text.txt");
        int x=-1;
        while (getline (myfile,patternline,'\n')) {
            ++x;
            array[x]=patternline;

        }
        cout<<"##############################################################LCSS"
        <<"################################################"<<endl;
        for(int i=0;i<=10;i++){
            flag=false;

            s=files[i];
            testfiles.open(files[i].c_str());
            checkLcss(s,array,x);
            if(flag==true){
                cout<<"Source : "<<files[i]<<endl;
                cout<<"===================="<<endl<<endl;
            }

                            testfiles.close();

        }
        cout<<"Percentage of Plagerized content in the main document : "<<(((double)lcs_count)/7)*100<<" %"<<endl;

    }
};

#endif /* LCSSheader_h */
