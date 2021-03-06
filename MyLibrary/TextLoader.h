#pragma once
#include<vector>
#include<string>

class TextLoader
{
private:
	static std::vector<std::string> stringTextData;


public:


#pragma region 読み込み

	static bool loadText(const char* path);

#pragma endregion



#pragma region 受け取り
	/// <summary>
	/// intに変換して二次元vectorに格納します(カンマは外されます)
	/// </summary>
	/// <returns></returns>
	static void getIntVector(std::vector<std::vector<int>>& intTextData);



#pragma endregion

};

