#include<iostream>
#include<algorithm>
#include<fstream>  

int main(){
    int n, m;
    std::string a, b;
    std::cin >> n;
    std::cin >> m;
    std::cin >> a;
    std::cin >> b;
    int lenSubstr, indexA, indexB, totalScore;
    int totalScoreGlobal = 0;
    std::string bestA, bestB;
    if(n>m){
        lenSubstr = m;
    }
    else{
        lenSubstr = n;
    }
    while(lenSubstr>=2){
        indexA = 0;
        while(indexA<n-lenSubstr){
            std::string subA = a.substr(indexA, lenSubstr);
            indexB = 0;
            while(indexB<m-lenSubstr){
                std::string subB = b.substr(indexB, lenSubstr);
                totalScore = 0;
                for(int i = 0; i<lenSubstr; i++){
                    if(subA[i] == subB[i]){
                        totalScore+=2;
                    }
                    else{
                        totalScore-=1;
                    }
                }
                if(totalScoreGlobal<totalScore){
                    totalScoreGlobal = totalScore;
                    bestA = subA;
                    bestB = subB;
                }
                indexB++;
                // std::cout << "subA: " << subA << std::endl << "subB: " << subB << std::endl;
            }
            indexA++;
        }
        lenSubstr--;
    }
    std::ofstream outfile ("output.txt");
    outfile << totalScoreGlobal << std::endl << "bestA: " << bestA << std::endl << "bestB: " << bestB << std::endl;
    outfile.close();
}