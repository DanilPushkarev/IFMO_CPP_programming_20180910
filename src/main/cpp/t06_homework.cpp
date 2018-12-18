//Учительница задала Пете домашнее задание — в заданном тексте расставить ударения в словах, 
// после чего поручила Васе проверить это домашнее задание. 
// Вася очень плохо знаком с данной темой, поэтому он нашел словарь, 
// в котором указано, как ставятся ударения в словах. 
// К сожалению, в этом словаре присутствуют не все слова. 
// Вася решил, что в словах, которых нет в словаре, он будет считать, 
// что Петя поставил ударения правильно, если в этом слове Петей поставлено ровно одно ударение.
//
//Оказалось, что в некоторых словах ударение может быть поставлено больше, чем одним способом. 
// Вася решил, что в этом случае если то, как Петя поставил ударение, 
// соответствует одному из приведенных в словаре вариантов, 
// он будет засчитывать это как правильную расстановку ударения, 
// а если не соответствует, то как ошибку.
//
//Вам дан словарь, которым пользовался Вася и домашнее задание, сданное Петей. 
// Ваша задача — определить количество ошибок, которое в этом задании насчитает Вася.
//
//Входные данные
//
//Вводится сначала число N — количество слов в словаре (0 ≤ N ≤ 20000).
//
//Далее идет N строк со словами из словаря. Каждое слово состоит не более чем из 30 символов. 
// Все слова состоят из маленьких и заглавных латинских букв. 
// В каждом слове заглавная ровно одна буква — та, на которую попадает ударение. 
// Слова в словаре расположены в алфавитном порядке. 
// Если есть несколько возможностей расстановки ударения в одном и том же слове, 
// то эти варианты в словаре идут в произвольном порядке.
//
//Далее идет упражнение, выполненное Петей. Упражнение представляет собой строку текста, 
// суммарным объемом не более 300000 символов. Строка состоит из слов, 
// которые разделяются между собой ровно одним пробелом. 
// Длина каждого слова не превышает 30 символов. 
// Все слова состоят из маленьких и заглавных латинских букв 
// (заглавными обозначены те буквы, над которыми Петя поставил ударение). 
// Петя мог по ошибке в каком-то слове поставить более одного ударения или не поставить ударения вовсе.
//
//Выходные данные
//
//Выведите количество ошибок в Петином тексте, которые найдет Вася.
//
//Примечание к примеру
//
//
//1. В слове cannot, согласно словарю возможно два варианта расстановки ударения. 
// Эти варианты в словаре могут быть перечислены в любом порядке 
// (т.е. как сначала cAnnot, а потом cannOt, так и наоборот).
//Две ошибки, совершенные Петей — это слова be (ударение вообще не поставлено) 
// и fouNd (ударение поставлено неверно). Слово thE отсутствует в словаре, 
// но поскольку в нем Петя поставил ровно одно ударение, признается верным.
//
//2. Неверно расставлены ударения во всех словах, кроме The (оно отсутствует в словаре,
// в нем поставлено ровно одно ударение). В остальных словах либо ударные все буквы (в слове PAGE),
// либо не поставлено ни одного ударения.
//
//
//Sample Input 1:
//
//4
//cAnnot
//cannOt
//fOund
//pAge
//thE pAge cAnnot be fouNd
//
//Sample Output 1:
//
//2
//
//Sample Input 2:
//
//4
//cAnnot
//cannOt
//fOund
//pAge
//The PAGE cannot be found
//Sample Output 2:
//
//4

#include "t06_homework.h"
#include <iostream>
#include <string>
#include <set>

using namespace std;

    string low(string s) {
        for (int i=0; i<s.size(); i++) s[i] = char(int(s[i]-int('a')+int('A')));
        return s;
    }

    int stress(string s) {
        int count=0;
        for (int i=0; i<s.size(); i++)
            if (s[i] >= 'A' and s[i] <= 'Z') count++;
        return count;
    }

    int t06_homework() {
        set <string> s, book;
        int n, mistakes = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s1;
            cin >> s1;
            s.insert(low(s1));
            book.insert(s1);
        }
        string s1;
        while (cin >> s1) {
            if (s.count(low(s1)) != 0) {
                if (book.count(s1) == 0) mistakes++;
            } else {
                if (stress(s1) != 1) mistakes++;
            }
        }
        cout << mistakes;
    }