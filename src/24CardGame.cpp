#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <bits/stdc++.h>
#include "function.cpp"
using namespace std;

int main()
{
    using Clock = chrono::high_resolution_clock;
    string file[1000];
    cout << "==========================================================================================" << endl;
    cout <<".------..------.     .------..------..------..------.     .------..------..------..------." << endl ;
    cout <<"|2.--. ||4.--. |.-.  |C.--. ||A.--. ||R.--. ||D.--. |.-.  |G.--. ||A.--. ||M.--. ||E.--. |" << endl ;
    cout <<"| (\\/) || :/\\: ((5)) | :/\\: || (\\/) || :(): || :/\\: ((5)) | :/\\: || (\\/) || (\\/) || (\\/) |" << endl ;
    cout <<"| :\\/: || :\\/: |'-.-.| :\\/: || :\\/: || ()() || (__) |'-.-.| :\\/: || :\\/: || :\\/: || :\\/: |" << endl ;
    cout <<"| '--'2|| '--'4| ((1)) '--'C|| '--'A|| '--'R|| '--'D| ((1)) '--'G|| '--'A|| '--'M|| '--'E|" << endl ;
    cout <<"`------'`------'  '-'`------'`------'`------'`------'  '-'`------'`------'`------'`------'" << endl ;
    cout << "==========================================================================================" << endl;
    cout << "                                  WELCOME";
    cout << " TO";
    cout << " 24 CARD GAME" << std::endl;
    cout << " PLEASE CHOOSE TYPE OF INPUT" << std::endl;
    cout << " 1. MANUAL" << std::endl;
    cout << " 2. RANDOM" << std::endl;
    vector <char> op;
    vector <int> numb1;
    vector <int> temp;
    int count;
    int choice;
    cin >> choice;
    double numb[4];
    switch (choice) {
        case 1:{
            cout << " MANUAL" << std::endl;
            string card[4];
            bool check = false;
            while(check == false){
                cout << " ENTER 4 NUMBERS" << std::endl;
                cin >> card[0] >> card[1] >> card[2] >> card[3];
            if(
            card[0] == "A" || card[1] == "A" || card[2] == "A" || card[3] == "A" ||
            card[0] == "2" || card[1] == "2" || card[2] == "2" || card[3] == "2" ||
            card[0] == "3" || card[1] == "3" || card[2] == "3" || card[3] == "3" ||
            card[0] == "4" || card[1] == "4" || card[2] == "4" || card[3] == "4" ||
            card[0] == "5" || card[1] == "5" || card[2] == "5" || card[3] == "5" ||
            card[0] == "6" || card[1] == "6" || card[2] == "6" || card[3] == "6" ||
            card[0] == "7" || card[1] == "7" || card[2] == "7" || card[3] == "7" || 
            card[0] == "8" || card[1] == "8" || card[2] == "8" || card[3] == "8" ||
            card[0] == "9" || card[1] == "9" || card[2] == "9" || card[3] == "9" ||
            card[0] == "10" || card[1] == "10" || card[2] == "10" || card[3] == "10" ||
            card[0] == "J" || card[1] == "J" || card[2] == "J" || card[3] == "J" ||
            card[0] == "Q" || card[1] == "Q" || card[2] == "Q" || card[3] == "Q" ||
            card[0] == "K" || card[1] == "K" || card[2] == "K" || card[3] == "K"||
            card[0] != card[1] || card[0] != card[2] || card[0] != card[3] || card[1] != card[2] || card[1] != card[3] || card[2] != card[3] )
            {
                check = true;
            
            }
            else
            {
                cout << " INVALID INPUT" << std::endl;
            }
            }
            
            for (int i = 0; i < 4 ; i++){
                if (card[i] == "A"){
                    numb[i] = 1;
                }
                else if (card[i] == "J"){
                    numb[i] = 11;
                }
                else if (card[i] == "Q"){
                    numb[i] = 12;
                }
                else if (card[i] == "K"){
                    numb[i] = 13;
                }
                else {
                    numb[i] = stoi(card[i]);
                }
            }
            break;
        }
        case 2:
            cout << " RANDOM" << std::endl;
            srand(time(0));
            for (int i = 0; i < 4; i++)
            {
                numb[i] = rand() % 13 + 1;
            }
            for (int i = 0; i < 4; i++)
            {
                if (numb[i] == 1){
                    cout << "A ";
                }
                else if (numb[i] == 11){
                    cout << "J ";
                }
                else if (numb[i] == 12){
                    cout << "Q ";
                }
                else if (numb[i] == 13){
                    cout << "K ";
                }
                \
                else {
                    cout << numb[i] << " ";
                }
            }
            cout << std::endl;
            break;
}
    auto start = Clock::now();
    mutasi(numb,temp, 0, 3);
    validmutasi(numb1, temp);
    operatorr(op);
    int x = 0;
    int j = 0;
    for (int i = 0; i < numb1.size(); i += 4){
    
            
            solution(op,numb1[i], numb1[i+1], numb1[i+2], numb1[i+3], &x , j, file, &count);
            solution2(op,numb1[i], numb1[i+1], numb1[i+2], numb1[i+3], &x , j, file, &count);
            solution3(op,numb1[i], numb1[i+1], numb1[i+2], numb1[i+3], &x , j, file, &count);
            solution4(op,numb1[i], numb1[i+1], numb1[i+2], numb1[i+3], &x , j, file, &count);
            solution5(op,numb1[i], numb1[i+1], numb1[i+2], numb1[i+3], &x , j, file, &count);
            j += 3;
        }
        
        cout << x << " Solution found" << std::endl;
        cout << endl;
        for (int i=0; i < count;i++){
            cout << file[i] << std::endl;
        }
        auto end = Clock::now();
        auto ms = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << " Time taken by program is : " << ms << " ms" << std::endl;
        string save;
        string name;
        cout << " DO U WANT TO SAVE THE RESULT ? (yay/nay) : ";
        cin >> save;
        if (save == "yay"){
            cout << " FILE NAME : ";
            cin >> name;
            name += ".txt";
            ofstream myfile;
            myfile.open("test/"+name);
            myfile << "Card :";
            for (int i=0; i<4; i++){
                myfile << " " << numb[i];
            }
            myfile << std::endl;
            myfile << "========================================" << std::endl;
            myfile << " " << x << " Solution" << std::endl;
            for (int i=0; i<count; i++){
                myfile << " " << file[i] << std::endl;
            }
            myfile.close();
        }
        else if (save == "nay"){
            cout << " SIPSIP" << std::endl;
        }
        else {
            cout << " INVALID INPUT" << std::endl;
        }
}