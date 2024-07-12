//#include <iostream>
//#include <vector>
//#include <opencv2/opencv.hpp>
//
//bool ReadImage(const std::string& str_imgs_folder, std::vector<cv::Mat>& vec_mat_imgs) {
//    std::vector<std::string> vec_imgs_name;
//    cv::glob(str_imgs_folder, vec_imgs_name, false);  // 查找指定文件夹下的所有 JPEG 图片
//    size_t i_imgs_num = vec_imgs_name.size();
//    if (i_imgs_num < 1) {
//        return false;
//    }
//    vec_mat_imgs.resize(i_imgs_num);
//    for (size_t i = 0; i < i_imgs_num; ++i) {
//        cv::Mat image = cv::imread(vec_imgs_name[i], cv::IMREAD_GRAYSCALE);
//        if (image.empty()) {
//            return false;
//        }
//        vec_mat_imgs[i] = image;
//    }
//    return true;
//}
//
//int main() {
//    std::string str_imgs_folder = "C:\\Users\\陈波\\OneDrive\\桌面\\cat";  // 文件夹路径
//    bool b_ret = false;
//    std::vector<cv::Mat> vec_mat_imgs;
//    b_ret = ReadImage(str_imgs_folder, vec_mat_imgs);
//    if (b_ret) {
//        std::cout << "读取图片成功！" << std::endl;
//    }
//    else {
//        std::cout << "读取图片失败！" << std::endl;
//    }
//    return 0;



//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
////数据集文件路径
//String catFileName = "E:\\Opencv\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalcatface.xml";
//CascadeClassifier catclassifier;
//int main(int argc, char** argv)
//{
//	if (!catclassifier.load(catFileName))//读取数据集，未找到，则结束，否则继续后面的操作
//	{
//		cout << "数据集未加载!" << endl;
//		return -1;
//	}
//	Mat src = imread("C:\\Users\\陈波\\OneDrive\\桌面\\1719121842304.jpg");//读进来包含猫脸的图片
//	if (src.empty())
//	{
//		cout << "图片未找到!" << endl;
//		return -1;
//	}
//	Mat gray;
//	cvtColor(src, gray, COLOR_BGR2BGRA);//转为灰度图
//	vector<Rect>face_cats;//存储猫脸数据
//	//在不同尺度空间上计算并检测猫脸
//	catclassifier.detectMultiScale(gray, face_cats, 1.1, 3, 0, Size(20, 20));
//	//绘制矩形框住猫脸
//	for (size_t i = 0; i < face_cats.size(); i++)
//	{
//		rectangle(src, face_cats[i], Scalar(0, 0, 255), 2, 8, 0);
//
//	}
//	imshow("face of cat detect", src);
//	waitKey(0);
//	return 0;
//}


//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//    // 加载猫脸检测分类器
//    CascadeClassifier catFaceCascade;
//    if (!catFaceCascade.load("E:\\Opencv\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalcatface.xml"))
//    {
//        cout << "无法加载猫脸分类器！" << endl;
//        return -1;
//    }
//
//    // 读取图像
//    Mat image = imread("C:\\Users\\陈波\\OneDrive\\桌面\\cat\\1718975257019.jpg");
//
//    // 转换为灰度图像
//    Mat grayImage;
//    cvtColor(image, grayImage, COLOR_BGR2GRAY);
//
//    // 图像预处理：去噪和增强对比度
//    GaussianBlur(grayImage, grayImage, Size(5, 5), 0);
//    equalizeHist(grayImage, grayImage);
//
//    // 多尺度检测
//    double scaleFactors[] = { 1.1, 1.2, 1.3 };
//    int minNeighbors = 5;
//    int flags = 0;
//    Size minSize(30, 30);
//    Size maxSize(200, 200);
//
//    vector<Rect> catFaces;
//    for (double scaleFactor : scaleFactors)
//    {
//        catFaceCascade.detectMultiScale(grayImage, catFaces, scaleFactor, minNeighbors, flags, minSize, maxSize);
//       
//    }
//
//    // 绘制检测到的猫脸矩形框
//    /*for (const Rect& face : catFaces)
//    {
//        rectangle(image, face, Scalar(0, 255, 0), 2,8,0);
//    }*/
//    for (size_t i = 0; i < catFaces.size(); i++)
//        	{
//        		rectangle(image, catFaces[i], Scalar(0, 0, 255), 2, 8, 0);
//        
//        	}
//
//    // 显示结果图像
//    imshow("Cat Faces", image);
//    waitKey(0);
//
//    return 0;
//}

//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//    // 加载猫脸检测分类器
//    CascadeClassifier catFaceCascade;
//    if (!catFaceCascade.load("E:\\Opencv\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalcatface.xml"))
//    {
//        cout << "无法加载猫脸分类器！" << endl;
//        return -1;
//    }
//
//    // 读取图像
//    Mat image = imread("C:\\Users\\陈波\\OneDrive\\桌面\\cat\\1718975276316.jpg");
//    if (image.empty())
//    {
//        cout << "图片未找到!" << endl;
//        return - 1;
//    }
//    // 转换为灰度图像
//    Mat grayImage;
//    cvtColor(image, grayImage, COLOR_BGR2GRAY);
//
//    // 图像预处理：去噪和增强对比度
//    GaussianBlur(grayImage, grayImage, Size(5, 5), 0);
//    equalizeHist(grayImage, grayImage);
//
//    // 多尺度检测
//    double scaleFactors[] = { 1.1, 1.2, 1.3 };
//    int minNeighbors = 5;
//    int flags = 0;
//    Size minSize(30, 30);
//    Size maxSize(200, 200);
//
//    vector<Rect> catFaces;
//    for (double scaleFactor : scaleFactors)
//    {
//        catFaceCascade.detectMultiScale(grayImage, catFaces, scaleFactor, minNeighbors, flags, minSize, maxSize);
//    }
//
//    // 根据检测结果添加描述
//    if (catFaces.size() > 0)
//    {
//        putText(image, "cat", Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 2);
//    }
//    else
//    {
//        putText(image, "not cat", Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2);
//    }
//
//    // 显示结果图像
//    imshow("Cat Faces", image);
//    waitKey(0);
//
//    return 0;
//}

//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <filesystem>
//#include <vector>
//using namespace std;
//using namespace cv;
//// 猫脸检测函数
//bool detectCatFace(const Mat& image) {
//    CascadeClassifier catFaceCascade;//加载猫脸分类器
//    if (!catFaceCascade.load("E:\\Opencv\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalcatface.xml")) {
//        std::cout << "无法加载猫脸分拣器！" << std::endl;
//        return false;
//    }
//
//    Mat grayImage;
//    cvtColor(image, grayImage, COLOR_BGR2GRAY);
//
//    vector<Rect> catFaces;
//    catFaceCascade.detectMultiScale(grayImage, catFaces, 1.1, 5);
//
//    return catFaces.size() > 0;
//}
//
//int main() {
//    string folderPath = "C:\\Users\\陈波\\OneDrive\\桌面\\cat"; // 文件夹路径
//
//    int totalImages = 0;
//    int correctCatFaceDetections = 0;
//
//    // 遍历文件夹中的每个文件和子文件夹
//    for (const auto& entry : filesystem::directory_iterator(folderPath))
//    {
//        // 是常规文件并且是图片格式（.jpg 或.png）
//        if (entry.is_regular_file() &&(entry.path().extension() == ".jpg" || entry.path().extension() == ".png")) 
//        {
//            Mat image = imread(entry.path().string());
//            // 如果图像读取失败，输出错误信息并继续
//            if (image.empty()) 
//            {
//                cout << "无法读取图像: " << entry.path().string() << endl;
//                continue;
//            }
//
//            bool isCatFace = detectCatFace(image);
//
//            // 设置为真实猫脸的标签（“cat")
//            bool isTrueCatFace = (entry.path().string().find("cat") != std::string::npos);     
//
//            totalImages++;
//
//            if (isCatFace == isTrueCatFace) {
//                correctCatFaceDetections++;
//            }
//        }
//    }
//
//    double accuracy = (double)correctCatFaceDetections / totalImages * 100;
//    cout << "猫脸检测的准确率为: " << accuracy << "%" << endl;
//
//    return 0;
//}

//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <filesystem>
//#include <vector>
//using namespace cv;
//using namespace std;
//// 猫脸检测函数
//bool detectCatFace(const cv::Mat& image) {
//    CascadeClassifier catFaceCascade;
//    if (!catFaceCascade.load("E:\\Opencv\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalcatface.xml")) {
//        std::cout << "无法加载猫脸分类器！" << std::endl;
//        return false;
//    }
//
//    cv::Mat grayImage;
//    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);//灰度化
//
//    std::vector<cv::Rect> catFaces;
//    catFaceCascade.detectMultiScale(grayImage, catFaces, 1.1, 5, 0, cv::Size(30, 30));
//
//    return catFaces.size() > 0;
//}
//
//int main() {
//    std::string folderPath = "C:\\Users\\陈波\\OneDrive\\桌面\\cat";//文件夹路径
//
//    int totalImages = 0;
//    int correctCatFaceDetections = 0;
//
//    for (const auto& entry : std::filesystem::recursive_directory_iterator(folderPath)) 
//    {
//        // 是常规文件并且是图片格式（.jpg 或.png）
//        if (entry.is_regular_file() &&((entry.path().extension() == ".jpg") || (entry.path().extension() == ".png"))) {
//            cv::Mat image = cv::imread(entry.path().string());
//            if (image.empty()) 
//            {
//                std::cout << "无法读取图像: " << entry.path().string() << std::endl;
//                continue;
//            }
//
//            bool isCatFace = detectCatFace(image);
//
//           // bool isTrueCatFace = (entry.path().string().find("cat") != std::string::npos);
//
//            totalImages++;
//
//            if (isCatFace) {
//                correctCatFaceDetections++;
//
//                // 显示检测到猫脸的图像
//                cv::namedWindow("Cat Face", cv::WINDOW_AUTOSIZE);
//                cv::imshow("Cat Face", image);
//                cv::waitKey(0);
//            }
//        }
//    }
//
//    double accuracy = static_cast<double>(correctCatFaceDetections) / totalImages * 100.0;
//    std::cout << "猫脸检测的准确率为: " << accuracy << "%" << std::endl;
//
//    return 0;
//}


















//
//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <filesystem>
//#include <vector>
//#include <fstream>  // 记录错误日志
//using namespace std;
//using namespace cv;
//
//// 猫脸检测函数
//bool detectCatFace(const cv::Mat& image, std::vector<cv::Rect>& catFaces) 
//{
//    CascadeClassifier catFaceCascade;
//    //导入猫脸分类器（haarcascades\\haarcascade_frontalcatface.xml）
//    if (!catFaceCascade.load("E:\\Opencv\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalcatface.xml"))
//    {
//        std::ofstream errorLog("error.log", std::ios_base::app);  // 打开错误日志文件
//        errorLog << "无法加载猫脸分类器！" << std::endl;
//        errorLog.close();  // 关闭文件
//        return false;
//    }
//
//    cv::Mat grayImage;
//    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);//图片灰度化处理
//    //使用加载的分类器在灰度图上进行多尺度的检测
//    catFaceCascade.detectMultiScale(grayImage, catFaces, 1.1, 5, 0, cv::Size(30, 30));
//
//    return catFaces.size() > 0;
//}
//
//// 计算准确率
//double calculateAccuracy(int totalImages, int correctCatFaceDetections) 
//{
//    return static_cast<double>(correctCatFaceDetections) / totalImages * 100.0;
//}
//
//int main() 
//{
//    std::string folderPath = "C:\\Users\\陈波\\OneDrive\\桌面\\cat";//文件夹路径
//
//    int totalImages = 0;
//    int correctCatFaceDetections = 0;
//
//    for (const auto& entry : std::filesystem::recursive_directory_iterator(folderPath))//使用  recursive_directory_iterator  来递归遍历文件夹及其子文件夹 
//    {
//        //常规图片格式（.jpg 或.png）
//        if (entry.is_regular_file() &&((entry.path().extension() == ".jpg") || (entry.path().extension() == ".png"))) 
//        {
//            cv::Mat image = cv::imread(entry.path().string());
//            if (image.empty())
//            {
//                std::ofstream errorLog("error.log", std::ios_base::app);
//                errorLog << "无法读取图像: " << entry.path().string() << std::endl;
//                errorLog.close();
//                continue;
//            }
//            std::vector<cv::Rect> catFaces;//存储猫脸的位置和大小
//            bool isCatFace = detectCatFace(image, catFaces);
//            totalImages++;
//            if (isCatFace) 
//            {
//                correctCatFaceDetections++;
//                //绘制矩形框住猫脸
//                for (size_t i = 0; i < catFaces.size(); i++)
//                    {
//                        rectangle(image, catFaces[i], Scalar(0, 0, 255), 2, 8, 0);
//                          
//                    }
//                // 显示检测到猫脸的图像
//                /*cv::namedWindow("Cat Face", cv::WINDOW_AUTOSIZE);
//                cv::imshow("Cat Face", image);
//                cv::waitKey(0);*/
//            }
//        }
//    }
//    double accuracy = calculateAccuracy(totalImages, correctCatFaceDetections);
//    std::cout << "猫脸检测的准确率为: " << accuracy << "%" << std::endl;
//
//    return 0;
//}

//
////
//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <filesystem>
//#include <vector>
//#include <fstream>  // 记录错误日志
//
// 
//using namespace std;
//using namespace cv;
//
//// 猫脸检测函数
//bool detectCatFace(const cv::Mat& image, std::vector<cv::Rect>& catFaces)
//{
//    CascadeClassifier catFaceCascade;
//    // 导入猫脸分类器（haarcascades\\haarcascade_frontalcatface.xml）
//    if (!catFaceCascade.load("E:\\Opencv\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalcatface.xml"))
//    {
//        std::ofstream errorLog("error.log", std::ios_base::app);  // 打开错误日志文件
//        errorLog << "无法加载猫脸分类器！" << std::endl;
//        errorLog.close();  // 关闭文件
//        return false;
//    }
//
//    cv::Mat grayImage;
//    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);// 图片灰度化处理
//    // 使用加载的分类器在灰度图上进行多尺度的检测
//    catFaceCascade.detectMultiScale(grayImage, catFaces, 1.1, 5, 0, cv::Size(30, 30));
//
//    return catFaces.size() > 0;
//}
//
//// 计算准确率
//double calculateAccuracy(int totalImages, int correctCatFaceDetections)
//{
//    return static_cast<double>(correctCatFaceDetections) / totalImages * 100.0;
//}
//
//int main()
//{
//    std::string folderPath = "C:\\Users\\陈波\\OneDrive\\桌面\\cat";// 文件夹路径
//
//    int totalImages = 0;
//    int correctCatFaceDetections = 0;
//
//    // 打开摄像头
//    VideoCapture cap(0);
//    if (!cap.isOpened())
//    {
//        std::cout << "无法打开摄像头" << std::endl;
//        return -1;
//    }
//
//    while (true)
//    {
//        cv::Mat frame;
//        cap >> frame;
//        if (frame.empty())
//        {
//            std::cout << "无法获取摄像头帧" << std::endl;
//            break;
//        }
//
//        std::vector<cv::Rect> catFaces;
//        bool isCatFace = detectCatFace(frame, catFaces);
//        totalImages++;
//        if (isCatFace)
//        {
//            correctCatFaceDetections++;
//            // 绘制矩形框住猫脸
//            for (size_t i = 0; i < catFaces.size(); i++)
//            {
//                rectangle(frame, catFaces[i], Scalar(0, 0, 255), 2, 8, 0);
//            }
//            // 显示检测到猫脸的图像
//            cv::namedWindow("Cat Face", cv::WINDOW_AUTOSIZE);
//            cv::imshow("Cat Face", frame);
//            if (cv::waitKey(1) == 27)
//            {
//                break;
//            }
//        }
//
//        for (const auto& entry : std::filesystem::recursive_directory_iterator(folderPath))// 使用  recursive_directory_iterator  来递归遍历文件夹及其子文件夹 
//        {
//            // 常规图片格式（.jpg 或.png）
//            if (entry.is_regular_file() && ((entry.path().extension() == ".jpg") || (entry.path().extension() == ".png")))
//            {
//                cv::Mat image = cv::imread(entry.path().string());
//                if (image.empty())
//                {
//                    std::ofstream errorLog("error.log", std::ios_base::app);
//                    errorLog << "无法读取图像: " << entry.path().string() << std::endl;
//                    errorLog.close();
//                    continue;
//                }
//                std::vector<cv::Rect> catFaces;// 存储猫脸的位置和大小
//                bool isCatFace = detectCatFace(image, catFaces);
//                totalImages++;
//                if (isCatFace)
//                {
//                    correctCatFaceDetections++;
//                    // 绘制矩形框住猫脸
//                    for (size_t i = 0; i < catFaces.size(); i++)
//                    {
//                        rectangle(image, catFaces[i], Scalar(0, 0, 255), 2, 8, 0);
//
//                    }
//                    // 显示检测到猫脸的图像
//                    cv::namedWindow("Cat Face", cv::WINDOW_AUTOSIZE);
//                    cv::imshow("Cat Face", image);
//                    cv::waitKey(0);
//                }
//            }
//        }
//    }
//
//    double accuracy = calculateAccuracy(totalImages, correctCatFaceDetections);
//    std::cout << "猫脸检测的准确率为: " << accuracy << "%" << std::endl;
//
//    return 0;
//}


//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace std;
//using namespace cv;
//
//// 猫脸检测函数
//bool detectCatFace(const Mat& image, vector<Rect>& catFaces)
//{
//    CascadeClassifier catFaceCascade;
//    // 导入猫脸分类器
//    if (!catFaceCascade.load("E:\\Opencv\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalcatface.xml"))
//    {
//        cout << "无法加载猫脸分类器！" << endl;
//        return false;
//    }
//
//    Mat grayImage;
//    cvtColor(image, grayImage, COLOR_BGR2GRAY);
//
//    catFaceCascade.detectMultiScale(grayImage, catFaces, 1.1, 5, 0, Size(30, 30));
//
//    return catFaces.size() > 0;
//}
//
//int main()
//{
//    // 打开摄像头
//    VideoCapture cap(0);
//    if (!cap.isOpened())
//    {
//        cout << "无法打开摄像头" << endl;
//        return -1;
//    }
//
//    while (true)
//    {
//        Mat frame;
//        cap >> frame;
//
//        vector<Rect> catFaces;
//        if (detectCatFace(frame, catFaces))
//        {
//            for (const auto& face : catFaces)
//            {
//                rectangle(frame, face, Scalar(0, 0, 255), 2);
//            }
//        }
//
//        imshow("Cat Face Detection", frame);
//
//        if (waitKey(1) == 27)
//        {
//            break;
//        }
//    }
//
//    return 0;
//}
//
//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace std;
//using namespace cv;
//
//// 猫脸检测函数
//bool detectCatFace(const Mat& image, vector<Rect>& catFaces)
//{
//    CascadeClassifier catFaceCascade;
//    // 导入猫脸分类器
//    if (!catFaceCascade.load("E:\\Opencv\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalcatface.xml"))
//    {
//        cout << "无法加载猫脸分类器！" << endl;
//        return false;
//    }
//    Mat grayImage;
//    cvtColor(image, grayImage, COLOR_BGR2GRAY);
//    catFaceCascade.detectMultiScale(grayImage, catFaces, 1.1, 5, 0, Size(30, 30));
//    return catFaces.size() > 0;
//}
//
//int main()
//{
//    // 打开摄像头
//    VideoCapture cap(0);
//    if (!cap.isOpened())
//    {
//        cout << "无法打开摄像头" << endl;
//        return -1;
//    }
//    while (true)
//    {
//        Mat frame;
//        cap >> frame;//捕获图像，将其存储进frame
//
//        vector<Rect> catFaces;
//        if (detectCatFace(frame, catFaces))
//        {
//            cout << "这是一只猫" << endl;
//            for (const auto& face : catFaces)
//            {
//                rectangle(frame, face, Scalar(0, 0, 255), 2);
//            }
//        }
//        imshow("Cat Face Detection", frame);
//        if (waitKey(1) == 27)
//        {
//            break;
//        }
//    }
//
//    return 0;
//}

