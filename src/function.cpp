#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void validmutasi(vector <int> &result, vector <int> old){
    bool check = false;
    result.push_back(old[0]);
    result.push_back(old[1]);
    result.push_back(old[2]);
    result.push_back(old[3]);
    // cout << result[0] << result[1] << result[2] << result[3] << endl;
    // cout << old[0] << old[1] << old[2] << old[3] << endl;
    for (int i = 4; i<old.size();i+=4){
        for (int j = 0; j<result.size();j+=4){
            if (old[i] != result[j] || old[i+1] != result[j+1] || old[i+2] != result[j+2] ||old[i+3] != result[j+3]){
                check = true;
            }
            else{
                check = false;
                break;
            }
            
        }
        if (check == true){
            result.push_back(old[i]);
            result.push_back(old[i+1]);
            result.push_back(old[i+2]);
            result.push_back(old[i+3]);
        }
    }
}
    


void mutasi(double arr[], vector <int> &result, int l, int r) {
    if (l == r) {
        for (int i = 0; i < 4; i++) {
            result.push_back(arr[i]);
        }
    } 
    else {
        for (int i = l; i <= r; i++) {
            swap(arr[l], arr[i]);
            mutasi(arr, result, l+1, r);
            swap(arr[l], arr[i]);
        }
    }
}

string inttostring(int x){
    string result;
    if (x == 1){
        result = "1";
    }
    else if (x == 2){
        result = "2";
    }
    else if (x == 3){
        result = "3";
    }
    else if (x == 4){
        result = "4";
    }
    else if (x == 5){
        result = "5";
    }
    else if (x == 6){
        result = "6";
    }
    else if (x == 7){
        result = "7";
    }
    else if (x == 8){
        result = "8";
    }
    else if (x == 9){
        result = "9";
    }
    else if (x == 10){
        result = "10";
    }
    else if (x == 11){
        result = "11";
    }
    else if (x == 12){
        result = "12";
    }
    else if (x == 13){
        result = "13";
    }
    else if (x == 14){
        result = "14";
    }
    else if (x == 15){
        result = "15";
    }
    else if (x == 16){
        result = "16";
    }
    else if (x == 17){
        result = "17";
    }
    else if (x == 18){
        result = "18";
    }
    else if (x == 19){
        result = "19";
    }
    else if (x == 20){
        result = "20";
    }
    else if (x == 21){
        result = "21";
    }
    else if (x == 22){
        result = "22";
    }
    else if (x == 23){
        result = "23";
    }
    else if (x == 24){
        result = "24";
    }
    return result;
}

char convertop(int op){
    switch (op){
        case 0:
            return '+';
            break;
        case 1:
            return '-';
            break;
        case 2:
            return '*';
            break;
        case 3:
            return '/';
            break;
    }

}

void operatorr(vector <char> &result){
    int i, j, k;
    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
            for (k = 0; k < 4; k++){
                    result.push_back(convertop(i));
                    result.push_back(convertop(j));
                    result.push_back(convertop(k));
                
            }
        }
    }
}

float operation (float x, float y, char z){
    switch (z){
        case '+':
            return x + y;
            break;
        case '-':
            return x - y;
            break;
        case '*':
            return x * y;
            break;
        case '/':
            return x / y;
            break;
    }
}

void solution(vector <char> result ,int a, int b, int c , int d, int *x, int j, string file[], int *count){
    float sum = 0;
    for (j = 0 ; j<result.size(); j+=3){
    sum = operation(operation(operation(a,b,result[j]),c,result[j+1]),d,result[j+2]); //((a+b)*c)/d
    if (sum == 24){
        // cout <<"((" << a << result[j] << b << ")" << result[j+1] << c << ")" << result[j+2] << d << endl;
        file[*count] = "((" + inttostring(a) + result[j] + inttostring(b) + ")" + result[j+1] + inttostring(c) + ")" + result[j+2] + inttostring(d);
        *x += 1;
        *count += 1;
    }
    }

}

void solution2(vector <char> result ,int a, int b, int c , int d, int *x, int j, string file[], int *count){
    float sum = 0;
    for (j = 0 ; j<result.size(); j+=3){
    sum = operation(operation(a,operation(b,c,result[j+1]),result[j]),d,result[j+2]); //(a*(b+c))/d
    if (sum == 24){
        // cout << "(" << a << result[j] << "(" << b << result[j+1] << c << "))" << result[j+2] << d << endl;
        file[*count] = "(" + inttostring(a) + result[j] + "(" + inttostring(b) + result[j+1] + inttostring(c) + "))" + result[j+2] + inttostring(d);
        *x += 1;
        *count += 1;
    }
    }


}

void solution3(vector <char> result ,int a, int b, int c , int d, int *x, int j, string file[], int *count){
    float sum = 0;
    for (j = 0 ; j<result.size(); j+=3){
    sum = operation(a,operation(operation(b,c,result[j+1]),d,result[j+2]),result[j]); // a/((b+c)*d)
    if (sum == 24){
        // cout << a << result[j] << "((" << b << result[j+1] << c << ")" << result[j+2] << d << ")" << endl;
        file[*count] = inttostring(a) + result[j] + "((" + inttostring(b) + result[j+1] + inttostring(c) + ")" + result[j+2] + inttostring(d) + ")";
        *x += 1;
        *count += 1;
    }
    }
}

void solution4(vector <char> result ,int a, int b, int c , int d, int *x, int j, string file[], int *count){
    float sum = 0;
    for (j = 0 ; j<result.size(); j+=3){
    sum = operation(a,operation(b,operation(c,d,result[j+2]),result[j+1]),result[j]); // a/(b*(c/d))
    if (sum == 24){
        // cout << a << result[j] << "(" << b << result[j+1] << "(" << c << result[j+2] << d << "))" << endl;
        file[*count] = inttostring(a) + result[j] + "(" + inttostring(b) + result[j+1] + "(" + inttostring(c) + result[j+2] + inttostring(d) + "))";
        *x += 1;
        *count += 1;
    }
    }
}

void solution5(vector <char> result ,int a, int b, int c , int d, int *x, int j, string file[], int *count){
    float sum = 0;
    for (j = 0 ; j<result.size(); j+=3){
    sum = operation(operation(a,b,result[j]),operation(c,d,result[j+2]),result[j+1]); //(a+b)/(c+d)
    if (sum == 24){
        // cout << "(" << a << result[j] << b << ")" << result[j+1] << "(" << c << result[j+2] << d << ")" << endl;
        file[*count] = "(" + inttostring(a) + result[j] + inttostring(b) + ")" + result[j+1] + "(" + inttostring(c) + result[j+2] + inttostring(d) + ")";
        *x += 1;
        *count += 1;
    }
    }
}



