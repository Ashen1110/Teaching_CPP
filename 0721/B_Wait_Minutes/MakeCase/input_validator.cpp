#include<fstream>
#include<iostream>
#include<sstream>
using namespace std;

const int N = 15; //測資筆數
const int BUFSIZE = 7000000;
void open_file(ifstream &finput,int t_case){
    string dir_path = "../data/secret/";  //資料夾相對路徑
    string input_file_name = to_string(t_case)+".in"; //檔案名稱
    string input_path = dir_path + input_file_name; //開啟檔案位置
    finput.open(input_path , ios::in); 
    if(!finput){
        cerr << "cannot open input file " << input_path << endl;
        exit(1);
    }
}
void check(ifstream &finput, int t_case){
    /* 放檢查Code */
    int sec;
    string buf; //buffer 字串
    stringstream buf_s;  // 字串串流
    string check; // 檢查用
    cerr << "in test " << t_case << endl;

    //讀入一行
    if(!getline(finput,buf)){
        cerr << "input error, missiing first line." << endl;
        exit(1);
    }
    buf_s << buf; //讀進字串串流

    // 確認一行是一個整數
    if(!(buf_s >> sec )){
        cerr << "input error, missiing variable sec" << endl;
        exit(1);
    }
    if((buf_s >> check)){
        cerr << "more input in first line." << endl;
        exit(1);
    }

    // 檢查範圍
    if(sec<0 || sec>2147483647){
        cerr << "input error, n is out of range." << endl;
        exit(1);
    }
    
    finput.ignore(); // 下次用串流讀入 所以先 ignore擋 \n
    buf_s.clear(); // 先將字串串流清空


    // 檢查是否有多餘測資
    if((buf_s >> check) || (finput >> check)){
        cerr << "more input." << endl;
        exit(1);
    }
    cerr <<  "ok"  << endl;
    
}
void close_file(ifstream &finput,int t_case){
    finput.close();
}
int main(){
    for(int i=1;i<=N;i++){
        ifstream finput;
        open_file(finput,i); //要讀入輸入檔
        check(finput,i); //檢查input格式
        close_file(finput,i); //關閉檔案
    }
}
