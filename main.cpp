#include<iostream>
#include<algorithm>
#include<fstream>  
#include <vector>

int strCompare(std::string subA, std::string subB, int lenSubstr){
    int totalScore = 0;
    for(int i = 0; i<=lenSubstr; i++){
            if(subA[i] == subB[i]){
                totalScore+=2;
            }
            else{
                totalScore-=1;
            }
        }
    return totalScore;
}

int main(){
    int n, m;
    std::string a, b;
    std::cin >> n;
    std::cin >> m;
    std::cin >> a;
    std::cin >> b;
    std::vector <std::string> ListaA{};
    std::vector <std::string> ListaB{};
    int lenSubstr, indexA, indexB, totalScore;
    int totalScoreGlobal = 0;
    std::string bestA, bestB; 
    if(n>m){
        lenSubstr = m;
    }
    else{
        lenSubstr = n;
    }
    // int quantidade = 0;
    int minLen=-1;
    while(lenSubstr>=2 && lenSubstr > minLen){
        indexA = 0;
        while(indexA<n-lenSubstr){
            std::string subA = a.substr(indexA, lenSubstr+1);
            auto foundA = std::find(ListaA.begin(), ListaA.end(), subA);
            if(foundA == ListaA.end()){
                ListaA.push_back(subA);
                indexB = 0;
                while(indexB<m-lenSubstr){
                    std::string subB = b.substr(indexB, lenSubstr+1);
                    auto foundB = std::find(ListaB.begin(), ListaB.end(), subB);
                    if(foundB == ListaB.end()){
                        ListaB.push_back(subB);
                        totalScore = strCompare(subA, subB, lenSubstr);
                        // quantidade++;
                        if(totalScoreGlobal<totalScore){
                            totalScoreGlobal = totalScore;
                            minLen = totalScoreGlobal/2+1;
                            bestA = subA;
                            bestB = subB;
                            std::cout << std::endl << "bestA: " << bestA << std::endl << "bestB: " << bestB << std::endl;
                        }
                        // std::cout << "subStr: " << lenSubstr << std::endl << "minLen: " << minLen << std::endl;
                    }
                    indexB++;
                    // std::cout << "maxScore: " << totalScoreGlobal << std::endl << "subA: " << subA << std::endl << "subB: " << subB << std::endl;
                }
                ListaB.clear();
            }
            indexA++;
        }
        lenSubstr--;
        ListaA.clear();
    }
    // std::cout << "combinacoes: " << quantidade << std::endl;
    std::ofstream outfile ("output.txt");
    outfile << totalScoreGlobal << std::endl << "bestA: " << bestA << std::endl << "bestB: " << bestB << std::endl;
    outfile.close();
}