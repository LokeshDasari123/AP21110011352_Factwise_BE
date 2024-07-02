#include <iostream>
#include <vector>
using namespace std;

int countLettersInNumbers() {
    vector<string> ones = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<string> teens = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen","seventeen", "eighteen", "nineteen"};
    vector<string> tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    int total_count = 0;
    for (int i=1;i<=1000;i++){
        if (i == 1000){
            total_count += string("onethousand").length();
        } 
        else{
            int h = i / 100;
            int tu = i % 100;
            if(h>0)
            {
                total_count += ones[h].length() + string("hundred").length();
                if (tu>0)
                {
                    total_count += string("and").length();
                }
            }
            if(tu<10)
            {
                total_count += ones[tu].length();
            } 
            else if (tu<20)
            {
                total_count += teens[tu - 10].length();
            } 
            else{
                int tensDigit = tu / 10;
                int unitsDigit = tu % 10;
                total_count += tens[tensDigit].length() + ones[unitsDigit].length();
            }
        }
    }
    return total_count;
}

int main() {
    int res = countLettersInNumbers();
    cout<<"Total letters used from 1 to 1000 is: "<<res<<endl;
    return 0;
}
