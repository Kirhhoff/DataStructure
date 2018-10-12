#include"Interface.h"
using namespace std;

Interface::Interface(string databaseFileName){
	cars=new LList<Car>;
	readDatabase(databaseFileName);
}
void Interface::readDatabase(string databaseFileName);
	fin.open(databaseFileName.c_str());
	if(!fin.is_open()){	
		cerr<<"Fail to open "<<databaseFileName<<endl;
		exit(0);
	}
	Car carReadFromFile;
	while(fin>>carReadFromFile)
		cars.insert(carReadFromFile);
	fin.clear();
}
Interface::~Interface(){
	delete cars;
	fin.close();
}
Interface interface;
void Interface::showEntries(){
	//system("cls");
	cout	<<"* * * * * *欢迎使用大松公司汽车信息管理* * * * * *"<<endl
		<<"  对公司的汽车你享有信息分享权，但是你得妥善驾驶  "<<endl
		<<"=                                                ="<<endl
		<<"=      1.输入汽车信息     2.显示汽车信息         ="<<endl
		<<"=                                                ="<<endl
		<<"=      3.查找汽车信息     4.删除汽车信息         ="<<endl
		<<"=                                                ="<<endl
		<<"=      5.插入汽车信息     6.修改汽车信息         ="<<endl
		<<"=                                                ="<<endl
		<<"=               7.汽车排序信息                   ="<<endl
		<<"=                                                ="<<endl
		<<"=           0.退出汽车信息管理系统               ="<<endl
		<<"=                                                ="<<endl
		<<"公司的车辆只允许工作之用。                       ="<<endl
		<<endl
		<<endl
		<<"               请输入功能选项：";
}

void Interface::operating(){
	while(true){
		int entrySelected;
		clean();
		showEntries();
		entrySelected=getEntryInput();
		if(entrySelected==-1)
			Error(INVALID_ENTRY);
		else if(entrySelected==0)
			return;
		else
			Entry(entrySelected);			
	}
}
int Interface::getEntryInput(){
	int entry;
	cin>>entry;
	if(!cin||entry<0||entry>MAX_ENTRY){
		entry=-1;
		cin.clear();	
	}
	while(cin.get()!='\n');
	return entry;
}

void Interface::Error(errorType error){
	switch(error){
		case INVALID_ENTRY:{
			cout<<"请输入有效的功能选项!按任意键重新输入";
			while(cin.get()!='\n');
			break;
		}
		default:	break;
	}
}

void Interface::clean(){
}

void Interface::Entry(int entryNumber){
	showEntry(entryNumber);
	logicOfEntry(entryNumber);
}

void Interface::showEntry(int entryNumber){
	switch(entryNumber){
	case 1:	cout<<"请依次输入汽车品牌、型号、颜色、车牌号、出厂年份、出厂月份、出厂日期"
				<<"以回车键结束输入"<<endl;
			break;
	case 2:{
		out<<right;
		out	<<setw(BAND_WIDTH)<<"汽车品牌"
		<<setw(MODEL_WIDTH)<<"型号"
		<<setw(COLOR_WIDTH)<<"颜色"
		<<setw(LICENSE_WIDTH)<<"车牌号"
		<<setw(DATE_WIDTH)<<"出厂日期"
		<<endl;
		cars->moveToStart();
		while(cars->length()&&!cars->atEnd()){
			cout<<cars->getValue();
			cars->next();
		}
	}
	}
}

void Interface::search(searchGist gistNumber){
	string gist;
	
	switch(gistNumber){
		case BAND:{
			clean();
			string gist;
			cout<<"请输入您要查询的汽车品牌：";
			cin>>gist;
			LList<Car>* result; 
			for(cars->moveToStart();;)
				if(cars->getValue().getBand()==gist)
					result->insert(car)
		}
		case MODEL:	{
			clean();
			string 		
		}
		case COLOR:		
		case LICENSE:
		case DATE:
		default:	Error(INVALID_SEARCH_GIST);
					break;
	}
}

void Interface::logicOfEntry(int entryNumber){
}
