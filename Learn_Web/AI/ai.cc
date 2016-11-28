#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class RULE_TYPE {
public:
  RULE_TYPE(string s) : result(s) {}
  string getresult() {
    return result;
  }
  void setresult(string s) {
    result = s;
  }
  void addcause(string cp) {
    cause_chain.push_back(cp);
  }
  bool findcause(vector<string> db) {   //检测能否推出
    if (cause_chain.size() == 0) {
      return false;
    }
    for (int i = 0; i < cause_chain.size(); ++i) {
      if (find(db.begin(), db.end(), cause_chain[i]) == db.end())
        return false;
    }
    return true;
  }
private:
  vector<string> cause_chain;
  string result;
};

vector<RULE_TYPE> KnowledgeBase;  //知识库
vector<string> DataBase; //用户录用的事实库
vector<string> Conclusion; //结论

void creatKB(); //创建知识库
void inputDB(); //录入事实
void think();
void explain();

int main() {
  creatKB();
  inputDB();
  think();
  explain();
  return 0;
}

void creatKB() {
  cout << "*********录入知识库*********" << endl;
  for (int i = 0; ; ++i) {
    string conclusion;
    cout << "结论(输入0结束):";
    cin >> conclusion;
    if (conclusion == "0")  break;
    RULE_TYPE rp(conclusion);
    for (int j = 0; ; ++j) {
      string condition;
      cout << "条件(输入0结束)" << j << ":";
      cin >> condition;
      if (condition == "0")  break;
      rp.addcause(condition);
    }
    KnowledgeBase.push_back(rp);
  }
}
void inputDB() {
  cout << "*********输入事实*********" << endl;
  string condition;
  for (int i = 0; ; ++i) {
    cout << "事实(输入0结束)" << i << ":";
    cin >> condition;
    if (condition == "0")  break;
    DataBase.push_back(condition);
  }
}
void think() {
  int flag = true;
  while (flag) {
    flag = false;
    vector<RULE_TYPE>::iterator know = KnowledgeBase.begin();
    while (know != KnowledgeBase.end()) {
      if (know->findcause(DataBase)) {
        if (find(DataBase.begin(), DataBase.end(), know->getresult()) == DataBase.end()) {
          Conclusion.push_back(know->getresult());
          DataBase.push_back(know->getresult());
          flag = true;
        }
      }
      ++know;
    }
  }
}
void explain() {
  cout << "推理得到的结论" << endl;
  for (int i = 0; i < Conclusion.size(); ++i) {
    cout << Conclusion[i] << endl;
  }
}
