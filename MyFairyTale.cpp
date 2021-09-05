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
    vector<string> character = {"������","����","ȣ����","����","����","��","�պ�",
    "���","����","���","�䳢","����","����","�糪��","������","����","��¯��",
    "����","������","������","õ��","�Ǹ�","���","�����","��","��","����"}; // �ι� 27 
    vector<string> object = {"��","å","������","�Ǹ�","���","��","�巹��",
    "��","��ȭ","����","����","�ð�","�ſ�","����ũ","�Ź�","����","����",
    "����","��","����","��ġ","����","��ä","�ٱ���","��","����","����"}; // ���� 27
    vector<string> action = {"����","�����ϴ�","��������","������ ������",
    "�Դ�","�ƿ��","�ῡ ���","�޸���","���ָ� �ϴ�","�뷡�� �θ���",
    "�丮�� �ϴ�","�Ѿ�����","�ɴ�","����","�Ӹ��� �ڸ���","ã��","���� ����"}; // �ൿ 17
    vector<string> end = {"�ູ�ϰ� ��Ҵ�ϴ�","�����ߴ�ϴ�",
    "���� ��ȥ �ϰ� �ƴ�ϴ�","������ϴ�","������ ���� ����ϴ�",
    "�����ߴ�ϴ�"}; // ������ ���� 6
    map<string, string> pick; // ���� �ܾ�, ����
    vector<string> story; // ����� ���丮
};

class Writer : public My_Book{
public:
    void run(); // ���α׷� ����
    void explanation(); // ����
    void write(); // ����
    void pick_words(); // �ܾ� �̱�
    void show_words(); // ���� �ܾ� ����
    void show_story(); // ���丮����
    void delete_story(int n); // ���丮 ����
    void save_story(); 
};

void Writer :: explanation(){
    cout << "----------------My Fairy Tale----------------" << endl;
    cout << "�� ���� ��"<< endl;
    cout << "1. ��ȭå�� ����� ���α׷� �Դϴ�." <<endl;
    cout << "2. �ι� �ܾ� 4��, ���� �ܾ� 4��, �ൿ �ܾ� 4��, ������ ���� 1���� �־� ���ϴ�." <<endl;
    cout << "3. �ܾ���� ����ؼ� ��ȭ�� ����� �ֽø� �˴ϴ�." << endl;
    cout << "4. ��! ��ȭ�� ���� ������ �������� ������ �մϴ�!" << endl;
    cout << "��ſ� ��ȭ�� ����� �ּ���!!" << endl;
    cout << "----------------------------------------------" << endl;
}
void Writer :: pick_words(){
    // shuffle and pick
    random_device rd;
    mt19937 g(rd());
    shuffle(character.begin(),character.end(),g);
    pick.insert(make_pair("�ι�1",character[0]));
    pick.insert(make_pair("�ι�2",character[1]));
    pick.insert(make_pair("�ι�3",character[2]));
    pick.insert(make_pair("�ι�4",character[3])); // �ι�
    shuffle(object.begin(),object.end(),g);
    pick.insert(make_pair("����1",object[0]));
    pick.insert(make_pair("����2",object[1]));
    pick.insert(make_pair("����3",object[2]));
    pick.insert(make_pair("����4",object[3])); // ����
    shuffle(action.begin(),action.end(),g);
    pick.insert(make_pair("�ൿ1",action[0]));
    pick.insert(make_pair("�ൿ2",action[1]));
    pick.insert(make_pair("�ൿ3",action[2]));
    pick.insert(make_pair("�ൿ4",action[3])); // �ൿ
    // end�� ��� �����ص� ������ �ʹ� ���� ���ͼ� ������ ����
    srand((unsigned int)time(NULL));
    int n = rand()%6; // 0 ~ 5
    pick.insert(make_pair("����",end[n])); // ������ ����
}
void Writer :: show_words(){
    cout << "���� ���� �ܾ�, ����" << endl;
    cout << "�ι� --> " << pick["�ι�1"] << " ," << pick["�ι�2"] << " ," << pick["�ι�3"] << " ," << pick["�ι�4"] << endl;
    cout << "���� --> " << pick["����1"] << " ," << pick["����2"] << " ," << pick["����3"] << " ," << pick["����4"] << endl;
    cout << "�ൿ --> " << pick["�ൿ1"] << " ," << pick["�ൿ2"] << " ," << pick["�ൿ3"] << " ," << pick["�ൿ4"] << endl;
    cout << "���� --> " << pick["����"] << endl;    
}
void Writer :: show_story(){
    if(story.empty() == true) cout << "�̾߱Ⱑ ����ֽ��ϴ�." << endl;
    for(int i=0;i<story.size();i++){
        cout << story[i] << endl;
    }
}
void Writer :: delete_story(int n){
    string s;
    cout << "\n���� ��ġ�� �̾߱⸦ �ٽ� ���ּ���! --->";
    cin.clear(); // ���ڿ��� ������ cin�� ������ ���� ���� �߻� 
    cin.ignore(); // ���� ���� ���� �ذ�
    cin >> s;
    story.at(n) = s;
}
void Writer :: save_story(){
    string title;
    cout << "������ �Է����ּ���! ---> ";
    cin.clear(); // ���ڿ��� ������ cin�� ������ ���� ���� �߻� 
    cin.ignore(); // ���� ���� ���� �ذ�
    cin >> title;
    string file_path = ".\\My Book_" + title+".pdf";
    ofstream fout(file_path);
    if(!fout){
        cout << "���� ���� ����";
    }
    fout << "----------" << title << "----------" << endl;
    for(int i=0;i<story.size();i++){
        fout << story[i] << endl;
    }
    fout.close(); 
    cout << "\n���� �Ϸ�!!\n" << endl;
}
void Writer :: write(){
    int cont,c=1,del;
    string s;
    while(c){
        cout << "\n�ܾ�� ---> 0" <<  endl;
        cout << "���� ---> 1" << endl;
        cout << "����� ---> 2" << endl;
        cout << "�� �̾߱� ���� ---> 3" << endl;
        cout << "���� ---> 4" << endl;
        cout << "�������� �� ����. �̾Ҵ� �ܾ�� �ۼ��� �̾߱Ⱑ ������ϴ�. --->5" << endl;
        cout << "--> ";

        cin >> cont;
        switch(cont){
            case 0: show_words();break;
            case 1: 
                cout << "�̾߱⸦ �������ּ���!! --> ";
                cin.clear(); // ���ڿ��� ������ cin�� ������ ���� ���� �߻� 
                cin.ignore(); // ���� ���� ���� �ذ�
                getline(cin,s);
                story.push_back(s);
                break;
            case 2:
                show_story();
                cout << "���� �̾߱��� ���� �Է����ּ���!\n" << "������ ���� 0~\n" << "-->";
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
        cout << "1. ����" << endl;
        cout << "2. ����" << endl;
        cout << "3. ����" << endl;
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