#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

class My_Book{
protected:
    vector<string> character = {"개구리","사자","호랑이","왕자","공주","왕","왕비",
    "기사","마왕","용사","토끼","여우","늑대","당나귀","나무꾼","마녀","베짱이",
    "개미","강아지","도깨비","천사","악마","까마귀","멧돼지","소","곰","거인"}; // 인물 27 
    vector<string> object = {"검","책","지팡이","피리","쟁기","옷","드레스",
    "공","금화","보물","음식","시계","거울","케이크","신발","인형","양초",
    "연필","떡","도끼","망치","망토","부채","바구니","종","밧줄","날개"}; // 물건 27
    vector<string> action = {"날다","공격하다","도망가다","함정에 빠지다",
    "먹다","꺠우다","잠에 들다","달리다","연주를 하다","노래를 부르다",
    "요리를 하다","넘어지다","앉다","가다","머리를 자르다","찾다","밖을 보다"}; // 행동 17
    vector<string> end = {"행복하게 살았답니다","성공했답니다",
    "둘은 결혼 하게 됐답니다","떠났답니다","집으로 돌아 갔답니다",
    "도착했답니다"}; // 마지막 문장 6
    map<string, string> pick; // 뽑은 단어, 문장
    vector<string> story; // 기록할 스토리
};

class Writer : public My_Book{
public:
    void run(); // 프로그램 시작
    void explanation(); // 설명서
    void write(); // 쓰기
    void pick_words(); // 단어 뽑기
    void show_words(); // 뽑은 단어 보기
    void show_story(); // 스토리보기
    void delete_story(int n); // 스토리 삭제
    void save_story(); 
};

void Writer :: explanation(){
    cout << "----------------My Fairy Tale----------------" << endl;
    cout << "※ 설명 ※"<< endl;
    cout << "1. 동화책을 만드는 프로그램 입니다." <<endl;
    cout << "2. 인물 단어 4개, 물건 단어 4개, 행동 단어 4개, 마지막 문장 1개가 주어 집니다." <<endl;
    cout << "3. 단어들을 사용해서 동화를 만들어 주시면 됩니다." << endl;
    cout << "4. 단! 동화의 끝은 마지막 문장으로 끝나야 합니다!" << endl;
    cout << "즐거운 동화를 만들어 주세요!!" << endl;
    cout << "----------------------------------------------" << endl;
}
void Writer :: pick_words(){
    // shuffle and pick
    random_device rd;
    mt19937 g(rd());
    shuffle(character.begin(),character.end(),g);
    pick.insert(make_pair("인물1",character[0]));
    pick.insert(make_pair("인물2",character[1]));
    pick.insert(make_pair("인물3",character[2]));
    pick.insert(make_pair("인물4",character[3])); // 인물
    shuffle(object.begin(),object.end(),g);
    pick.insert(make_pair("물건1",object[0]));
    pick.insert(make_pair("물건2",object[1]));
    pick.insert(make_pair("물건3",object[2]));
    pick.insert(make_pair("물건4",object[3])); // 물건
    shuffle(action.begin(),action.end(),g);
    pick.insert(make_pair("행동1",action[0]));
    pick.insert(make_pair("행동2",action[1]));
    pick.insert(make_pair("행동3",action[2]));
    pick.insert(make_pair("행동4",action[3])); // 행동
    // end는 적어서 셔플해도 같은게 너무 자주 나와서 난수로 설정
    srand((unsigned int)time(NULL));
    int n = rand()%6; // 0 ~ 5
    pick.insert(make_pair("문장",end[n])); // 마지막 문장
}
void Writer :: show_words(){
    cout << "내가 뽑은 단어, 문장" << endl;
    cout << "인물 --> " << pick["인물1"] << " ," << pick["인물2"] << " ," << pick["인물3"] << " ," << pick["인물4"] << endl;
    cout << "물건 --> " << pick["물건1"] << " ," << pick["물건2"] << " ," << pick["물건3"] << " ," << pick["물건4"] << endl;
    cout << "행동 --> " << pick["행동1"] << " ," << pick["행동2"] << " ," << pick["행동3"] << " ," << pick["행동4"] << endl;
    cout << "문장 --> " << pick["문장"] << endl;    
}
void Writer :: show_story(){
    if(story.empty() == true) cout << "이야기가 비어있습니다." << endl;
    for(int i=0;i<story.size();i++){
        cout << story[i] << endl;
    }
}
void Writer :: delete_story(int n){
    string s;
    cout << "\n지운 위치에 이야기를 다시 써주세요! --->";
    cin.clear(); // 문자열과 정수를 cin에 넣으면 무한 루프 발생 
    cin.ignore(); // 무한 루프 오류 해결
    cin >> s;
    story.at(n) = s;
}
void Writer :: save_story(){
    string title;
    cout << "제목을 입력해주세요! ---> ";
    cin.clear(); // 문자열과 정수를 cin에 넣으면 무한 루프 발생 
    cin.ignore(); // 무한 루프 오류 해결
    cin >> title;
    string file_path = ".\\My Book_" + title+".pdf";
    ofstream fout(file_path);
    if(!fout){
        cout << "파일 열기 실패";
    }
    fout << "----------" << title << "----------" << endl;
    for(int i=0;i<story.size();i++){
        fout << story[i] << endl;
    }
    fout.close(); 
    cout << "\n생성 완료!!\n" << endl;
}
void Writer :: write(){
    int cont,c=1,del;
    string s;
    while(c){
        cout << "\n단어보기 ---> 0" <<  endl;
        cout << "쓰기 ---> 1" << endl;
        cout << "지우기 ---> 2" << endl;
        cout << "쓴 이야기 보기 ---> 3" << endl;
        cout << "저장 ---> 4" << endl;
        cout << "메인으로 ★ 주의. 뽑았던 단어와 작성한 이야기가 사라집니다. --->5" << endl;
        cout << "--> ";

        cin >> cont;
        switch(cont){
            case 0: show_words();break;
            case 1: 
                cout << "이야기를 시작해주세요!! --> ";
                cin.clear(); // 문자열과 정수를 cin에 넣으면 무한 루프 발생 
                cin.ignore(); // 무한 루프 오류 해결
                getline(cin,s);
                story.push_back(s);
                break;
            case 2:
                show_story();
                cout << "지울 이야기의 줄을 입력해주세요!\n" << "위에서 부터 0~\n" << "-->";
                getline(cin,s);
                cin.ignore(256,'\n');
                break;
            case 3:
                show_story(); 
                break;
            case 4:
                save_story();
                break;
            case 5: 
                c=0;
                pick.clear();
                story.erase(story.begin(),story.end());
                break;
        }
    }
}
void Writer :: run(){
    int pick;
    while(true){
        cout << "----------------My Fairy Tale----------------" << endl;
        cout << "1. 시작" << endl;
        cout << "2. 종료" << endl;
        cout << "3. 도움말" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "--> ";
        cin >> pick;
        switch(pick){
            case 1: pick_words();write();break;
            case 2: exit(1);break;
            case 3: explanation();break;
        }
    }
}


int main(){
    Writer start;
    start.run();
}