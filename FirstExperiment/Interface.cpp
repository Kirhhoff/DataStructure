#include"Interface.h"
#include"config.h"
#include"KVpair.h"
#include<unistd.h>
#include<iomanip>
#include<iostream>
using namespace std;

string carDatabase="CarDatabase.txt";
Interface interface(carDatabase);

/***********************************************************************************************
 * These are public constructors and destructor.
 */
Interface::Interface(string carDatabase):databaseFile(carDatabase){
	backup(databaseFile);
	readDatabase(databaseFile);
}
Interface::~Interface(){
	sync();
}

/************************************************************************************************
 * These are public methods
 */
void Interface::operating(){
	while(true){
		clean();//Clean screen every time before showing the entries.
		showEntries();
		int entrySelected=getEntryInput();
		switch(entrySelected){
			case INVALID_ENTRY:	{
				cout<<"请输入有效的功能选项!按任意键重新输入"<<endl;
				while(cin.get()!='\n');
				break;
			}
			case QUIT:			return;
			default:{
				clean();//Clean screen for later showing different entries.
				Entry(entrySelected);
				break;
			}			
		}
	}
}
void Interface::clean()const{system("clear");}
void Interface::showEntries(){
	cout<<"* * * * * *欢迎使用大松公司汽车信息管理* * * * * *"<<endl
		<<"  对公司的汽车你享有信息分享权，但是你得妥善驾驶  "<<endl
		<<"=                                                ="<<endl
		<<"=      1.显示汽车信息     2.添加汽车信息         ="<<endl
		<<"=                                                ="<<endl
		<<"=      3.删除汽车信息     4.更新汽车信息         ="<<endl
		<<"=                                                ="<<endl
		<<"=      5.查询汽车信息                            ="<<endl
		<<"=                                                ="<<endl
		<<"=                                                ="<<endl
		<<"=           0.退出汽车信息管理系统               ="<<endl
		<<"=                                                ="<<endl
		<<"公司的车辆只允许工作之用。                       ="<<endl
		<<endl
		<<endl
		<<"               请输入功能选项：";
}
void Interface::Entry(int entryNumber){
	switch(entryNumber){
		case SHOW_CARS:		showCars();
			break;
		case INSERT_CARS:	insertCars();
			break;
		case DELETE_CARS:	deleteCars();
			break;
		case UPDATE_CARS:	updateCars();
			break;
		case SEARCH_CARS:	searchCars();
			break;
		default:
			break;
	}
}
LList<KVpair<Key,Car>>* Interface::search(searchGist gistNumber){
	string stringGist;
	Date dateGist;
	LList<KVpair<Key,Car>>& pairList=dictionary.getPairList();
	LList<KVpair<Key,Car>>* result=new LList<KVpair<Key,Car>>;;
	KVpair<Key,Car> carGotFromCars;
	while(true){
	clean();
	switch(gistNumber){
		case HASH:
		case BAND:
		case MODEL:
		case COLOR:
		case LICENSE:{
			cout<<"请输入您的条件值："<<endl;
			cin>>stringGist;
			goto valid;
		}
		case DATE:{
			cout<<"请输入您的条件值：(如1999 10 25)"<<endl;
			cin>>dateGist;
			if(!cin){
				cin.clear();
				while(cin.get()!='\n');
				cout<<"无效的日期！"<<endl
					<<"输入q退出或其他任意键重新输入日期"<<endl;
				char input;
				input=cin.peek();
				while(cin.get()!='\n');
				if(input=='q'){
					clean();
					return result;
				}
			}
			else goto valid;
		}
	}
	}
	valid:{cin.get();}
	for(pairList.moveToStart();!pairList.atEnd();pairList.next()){
		string stringCmp;
		Date dateCmp;
		switch(gistNumber){
			case HASH:		stringCmp=static_cast<string>(pairList.getValue().getKey());
				break;
			case BAND:		stringCmp=pairList.getValue().getValue().getBand();
				break;
			case MODEL:		stringCmp=pairList.getValue().getValue().getModel();
				break;
			case COLOR:		stringCmp=pairList.getValue().getValue().getColor();
				break;
			case LICENSE:	stringCmp=pairList.getValue().getValue().getLicense();
				break;
			case DATE:		dateCmp=pairList.getValue().getValue().getProducedDate();
				break;
			default:
				break;
		}
		switch(gistNumber){
			case HASH:
			case BAND:
			case MODEL:
			case COLOR:
			case LICENSE:{
				if(stringCmp==stringGist)
					result->insert(pairList.getValue());
				break;
			}
			case DATE:{
				if(dateGist==dateCmp)
					result->insert(pairList.getValue());
				break;
			}
			default:
				break;
		}

	}
	return result;
}
/************************************************************************************************
 * These are different function entrances
 */
void Interface::showCars(){
	LList<KVpair<Key,Car>>& pairList=dictionary.getPairList();
	cout<<right
		<<setw(HASH_WIDTH)<<"汽车编号"
		<<setw(BAND_WIDTH)<<"汽车品牌"
		<<setw(MODEL_WIDTH)<<"型号"
		<<setw(COLOR_WIDTH)<<"颜色"
		<<setw(LICENSE_WIDTH)<<"车牌号"
		<<setw(DATE_WIDTH)<<"出厂日期"
		<<endl;
	showPairList(&pairList);
	cout<<endl<<"按任意键回到主菜单"<<endl;
	while(cin.get()!='\n');
}
void Interface::insertCars(){
	Car carReceipt;
	while(true){
		cout<<"请依次输入汽车品牌、型号、颜色、车牌号、出厂年份、出厂月份、出厂日期"<<endl
			<<"例如 丰田 G502 蓝色 鲁Q2685 1999 07 25"<<endl
			<<"以回车键结束输入"<<endl
			<<endl;
		switch(getCarInput(carReceipt)){
			case INVALID_CAR_INFO:cout<<"无效的汽车信息！"<<endl<<"按q键退出或按其他任意键重新输入"<<endl;
				break;
			case INVALID_DATE:cout<<"无效的日期信息！"<<endl<<"按q键退出或按其他任意键重新输入"<<endl;
				break;
			case FINE:
			default:{
				dictionary.insert(carReceipt);
				cout<<"添加汽车信息成功！"<<endl<<"按q键退出或其他任意键继续添加"<<endl;
				break;
			}
		}
		char input=cin.peek();
		while(cin.get()!='\n');
		if(input=='q')
			return;
		clean();
	}
}
void Interface::deleteCars(){
	while(true){
		string hashCode;
		cout<<"请输入要删除的汽车编号：";
		cin>>hashCode;
		if(dictionary.remove(hashCode))
			cout<<"删除成功！";
		else cout<<"删除失败，未找到该编号！";
		while(cin.get()!='\n');
		cout<<"按q键推出或按其他任意键继续删除"<<endl;
		char input=cin.peek();
		while(cin.get()!='\n');
		if(input=='q')
			return;
		clean();
	}
}
void Interface::updateCars(){
	string hashCode;
	while(true){
		cout<<"请输入要更新的汽车编号："<<endl;
		cin>>hashCode;
		cin.get();//Read the escape character after the input.
		Car foundCar;
		if(dictionary.find(hashCode,foundCar)){
			cout<<"汽车存在，信息为："<<endl<<KVpair<Key,Car>(Key(hashCode),foundCar)<<endl
				<<"请输入要更新的汽车信息，依次为汽车品牌、型号、颜色、车牌号、出厂年份、出厂月份、出厂日期"<<endl
				<<"例如 丰田 G502 蓝色 鲁Q2685 1999 07 25"<<endl
				<<"以回车键结束输入"<<endl
				<<endl;
			switch(getCarInput(foundCar)){
				case INVALID_CAR_INFO:cout<<"无效的汽车信息！"<<endl<<"按q键退出或按其他任意键重新输入"<<endl;
					break;
				case INVALID_DATE:cout<<"无效的日期信息！"<<endl<<"按q键退出或按其他任意键重新输入"<<endl;
					break;
				case FINE:
				default:{
					dictionary.remove();
					dictionary.insert(KVpair<Key,Car>(Key(hashCode),foundCar));
					cout<<"更新汽车信息成功！"<<endl<<"按q键退出或其他任意键继续更新"<<endl;
					break;
				}
			}
		}else cout<<"未找到该编号对应的汽车信息"<<endl<<"按q键退出或按其他任意键重新输入"<<endl;
		char input=cin.peek();
		while(cin.get()!='\n');
		if(input=='q')
			return;
		clean();
	}
}
void Interface::searchCars(){
	while(true){
		LList<KVpair<Key,Car>>* result=0;
		int gistNumber;
		cout<<"请输入您的搜索依据，代号分别为"<<endl
			<<"1.编号 2.品牌 3.型号 4.颜色 5.车牌号 6.出厂日期"<<endl;
		if(INVALID_GIST_NUMBER==(gistNumber=getGistNumber()))
			cout<<"无效的查找依据"<<endl;
		else result=search(gistNumber);
		showPairList(result);
		if(result)
			delete result;
		cout<<"按q退出或按其他任意键重新搜索"<<endl;
		char input;
		input=cin.peek();
		while(cin.get()!='\n');
		if(input=='q')
			return;
		clean();
	}
}

/************************************************************************************************
 * These are private methods
 */
void Interface::readDatabase(string databaseFileName){
	fin.open(databaseFileName.c_str());
	if(!fin.is_open()){
		cerr<<"Fail to open "<<databaseFileName<<" when trying to read data from it"<<endl;
		exit(0);
	}
	KVpair<Key,Car> pairReadFromFile;
	while(fin>>pairReadFromFile)
		dictionary.insert(pairReadFromFile);
	fin.clear();
	fin.close();
}
void Interface::backup(string databaseToBackup){
	string backupFile=databaseToBackup+".swap";
	const int bufferSize=200;
	char infoBuffer[bufferSize];
	fin.open(databaseFile.c_str());
	fin.seekg(0,ios::beg);
	if(!fin.is_open()){
		cerr<<"Fail to open database file to read when trying to back it up"<<endl;
		exit(0);
	}
	fout.open(backupFile.c_str());
	if(!fout.is_open()){
		cerr<<"Fail to open back-up file to write when trying to back uo"<<endl;
		exit(0);	
	}
	while(!fin.eof()){
		fin.getline(infoBuffer,bufferSize);
		fout<<infoBuffer<<endl;
	}
	fin.clear();
	fin.close();
	fout.close();
}
void Interface::sync(){
	fout.open(databaseFile);
	if(!fout.is_open()){
		cerr<<"Fail to open file "<<databaseFile<<" when trying to synchronize."<<endl;
		exit(0);
	}
	LList<KVpair<Key,Car>>& pairList=dictionary.getPairList();
	pairList.moveToStart();
	while(!pairList.atEnd()){
		fout<<pairList.getValue()<<endl;
		pairList.next();
	}
	fout.close();
}
int Interface::getEntryInput(){
	int entry;
	cin>>entry;
	if(!cin||entry<0||entry>MAX_ENTRY){
		entry=INVALID_ENTRY;
		cin.clear();
	}
	while(cin.get()!='\n');
	return entry;
}
int Interface::getCarInput(Car& carReceipt){
	string band;
	string model;
	string color;
	string license;
	Date producedDate;
	cin>>band>>model>>color>>license;
	if(!cin){
		cin.clear();
		while(cin.get()!='\n');
		return INVALID_CAR_INFO;
	}
	cin>>producedDate.year>>producedDate.month>>producedDate.day;
	if(!cin){
		cin.clear();
		while(cin.get()!='\n');
		return INVALID_DATE;
	}
	while(cin.get()!='\n');//Clean the input buffer.
	if(producedDate.year<1000||producedDate.year>3000||producedDate.month<1||producedDate.month>12||producedDate.day<1||producedDate.day>31)
		return INVALID_DATE;
	carReceipt.setBand(band);
	carReceipt.setModel(model);
	carReceipt.setColor(color);
	carReceipt.setLicense(license);
	carReceipt.setProducedDate(producedDate);
	return FINE;
}
int Interface::getGistNumber(){
	int gistNumber;
	cin>>gistNumber;
	if(!cin||gistNumber>MAX_GIST){
		cin.clear();
		while(cin.get()!='\n');
		return INVALID_GIST_NUMBER;
	}
	cin.get();
	return gistNumber;
}
void Interface::showPairList(LList<KVpair<Key,Car>>* pairList){
	if(!pairList)
		return;
	pairList->moveToStart();
	while(pairList->length()&&!pairList->atEnd()){
		cout<<pairList->getValue()<<endl;
		pairList->next();
	}
}
