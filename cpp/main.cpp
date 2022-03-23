#include <stdio.h>
#include <string>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <cctype>

using namespace std;

// std::transform で使うキャピタライズ(頭文字を大文字にすること)を実装する C++ 構造体です。
struct tocapital
{
    // m_beginning で単語の先頭かどうかを記録します。
    bool m_beginning;
    // 最初は単語の先頭として扱うように、コンストラクタで初期化します。
    tocapital(){
        m_beginning = true;
    }
    // std::transform で 1 文字毎に呼び出される () 演算子です。
    int operator()(int word){
        int result;
        if (std::isspace(word) != 0){
            // 空白文字であれば、次の文字は先頭文字です。空白文字は変換を通さずそのまま返します。
            m_beginning = true;
            result = word;
        }
        else{
            // 空白文字でなければ、先頭文字かどうかで変換方法を切り替えます。
            if (m_beginning) {
                // 先頭文字の場合は大文字に変換します。そして、以降の文字は先頭ではないと記録しておきます。
                m_beginning = false;
                result = toupper(word);
            }
            else {
                // 先頭ではない文字は小文字に変換します。
                result = tolower(word);
            }
        }
    return result;
    }
};

bool do_fizzbuzz(int turns, std::string type){

    std::string first_w = "";
    if (type == "bizz"){
        first_w = "Bizz";
    } else{
        first_w = "Fizz";
    }

    for (int i = 1; i < turns+1; i++){
        std::string kwd = "";
        if (i % 3 == 0){
            kwd = std::string(first_w);
        } if (i % 5 == 0 & kwd == ""){
            kwd = kwd + std::string("Buzz");
        } if (i % 5 == 0 & kwd == std::string(first_w)){
            kwd = kwd + std::string(" Buzz");
        }
        if ( kwd == ""){
            kwd = std::to_string(i);
        }
        printf("%s\n", kwd.c_str());
        /* code */
    }
    return true;
};

bool play_fizzbizz(int turns, std::string type){

    std::string first_w = "";
    if (type == "bizz"){
        first_w = "Bizz";
    } else{
        first_w = "Fizz";
    }

    clock_t start = clock();

    for (int i = 1; i < turns+1; i++){
        std::string kwd = "";
        std::string ans = "";
        std::string ans_c = "";

        if (i % 2 == 0){
            string fullName;
            cout << "";
            getline(cin, fullName);
            // cout << "" << fullName;
            ans = fullName;
            std::string ans_c;
            std::transform(ans.cbegin(), ans.cend(), ans.begin(), tocapital());
        }

        if (i % 3 == 0){
            kwd = std::string(first_w);
        } if (i % 5 == 0 & kwd == ""){
            kwd = kwd + std::string("Buzz");
        } if (i % 5 == 0 & kwd == std::string(first_w)){
            kwd = kwd + std::string(" Buzz");
        }
        if ( kwd == ""){
            kwd = std::to_string(i);
        }
        if (i % 2 != 0){
            printf("%s\n", kwd.c_str());
        }
        if (i == 10){
            printf("%s\n", kwd.c_str());
        }
        if (i % 2 == 0 & ans != std::string(kwd) & ans_c != std::string(kwd)){
            printf("You missed!");
            return false;
        }
    }

    clock_t end = clock();
    const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    printf("You win!");
    printf("time %0.3f[s]\n", time/1000);
    return true;
};

int main(){
    int turns = 12;
    std::string type = "fizz";
    // do_fizzbuzz(turns, type);
    play_fizzbizz(turns, type);
}