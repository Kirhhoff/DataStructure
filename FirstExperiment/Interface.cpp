#include"Interface.h"
#include"config.h"
#include<iomanip>
using namespace std;
Interface interface(carDatabase);

/***********************************************************************************************/
Interface::Interface(string carDatabase):databaseFile(carDatabase){
	cars=new LList<Car>;
	backup(databaseFile);
	readDatabase(databaseFile);
}
Interface::~Interface(){
	sync();
	delete cars;
	fin.close();
}

/**************************************************************************************************/
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
void Interface::clean(){system("reset");}
void Interface::showEntries(){
	cout	<<"* * * * * *欢迎使用大松公司汽车信息管理* * * * * *"<<endl
		<<"  对公司的汽车你享有信息分享权，但是你得妥善驾驶  "<<endl
		<<"=                                                ="<<endl
		<<"=      1.显示汽车信息     2.添加汽车信息         ="<<endl
		<<"=                                                ="<<endlFile
		<<"=      3.删除汽车信息     4.更新汽车信息         ="<<endl
		<<"=                                                ="<<endl
		<<"=      5.查询汽车信息                          ="<<endl
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
		case SHOW_CARS:	{
			cout<<right
				<<setw(HASH_WIDTH)<<"汽车编号"
				<<setw(BAND_WIDTH)<<"汽车品牌"
				<<setw(MODEL_WIDTH)<<"型号"
				<<setw(COLOR_WIDTH)<<"颜色"
				<<setw(LICENSE_WIDTH)<<"车牌号"
				<<setw(DATE_WIDTH)<<"出厂日期"
				<<endl;
			cars->moveToStart();
			while(cars->length()&&!cars->atEnd()){
				cout<<cars->getValue()<<endl;
				cars->next();
			}
			cout<<endl<<"按任意键回到主菜单"<<endl;
			while(cin.get()!='\n');
			return;
		}
		case INSERT_CARS:{
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
						cars->insert(carReceipt);
						cout<<"添加汽车信息成功！"<<endl<<"按q键退出或其他任意键继续添加"<<endl;
						break;
					}
				}
				if(cin.get()=='q')
					return;
				clean();
				while(cin.get()!='\n');
			}
		}
		case DELETE_CARS:{
			while(true){
				cout<<"请输入要删除的汽车编号：";
				//

			}
			break;
		}
		case UPDATE_CARS:{
			cout<<"请输入要更新的汽车编号：";
			break;
		}			
		case SEARCH_CARS:{
			break;
		}
	}
}
void Interface::readDatabase(string databaseFileName){
	fin.open(databaseFileName.c_str());
	if(!fin.is_open()){	
		cerr<<"Fail to open "<<databaseFileName<<endl;
		exit(0);
	}
	Car carReadFromFile;
	while(fin>>carReadFromFile)
		cars->insert(carReadFromFile);
	fin.clear();
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
	if(producedDate.year<1000||producedDate.year>3000||producedDate.month<1||producedDate.month>12||producedDate.day<1||producedDate.day>31)
		return INVALID_DATE;
	carReceipt.setBand(band);
	carReceipt.setModel(model);
	carReceipt.setColor(color);
	carReceipt.setLicense(license);
	return FINE;
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

LList<Car>* Interface::search(searchGist gistNumber){
	string gist;
	
	switch(gistNumber){
		case BAND:{
			clean();
			string gist;
			Car carGotFromCars;
			LList<Car>* result; 
			
			cout<<"请输入您要查询的汽车品牌：";
			cin>>gist;
			for(cars->moveToStart();!cars->atEnd();cars->next())
				if((carGotFromCars=cars->getValue()).getBand()==gist)
					result->insert(carGotFromCars);
			return result;
		}
		case MODEL:	{
			clean();
			//string 		
		}
		case COLOR:		
		case LICENSE:
		case DATE:
		default:	Error(INVALID_SEARCH_GIST);
					break;
	}
}
void Interface::sync(){
	fout.open(databaseFile);
	cars->moveToStart();
	while(!cars->atEnd()){
		fout<<cars->getValue()<<endl;
		cars->next();
	}
	fout.close();
}
void Interface::backup(string databaseToBackup){
	const int bufferSize=100;
	char infoBuffer[bufferSize];
	string backupFile=databaseToBackup+".swap";
	fin.open(databaseFile.c_str());
	fout.open(backupFile.c_str());
	while(fin.getline(infoBuffer,bufferSize))
		fout<<infoBuffer<<endl;
	fin.clear();
	fin.close();
	fout.close();
}