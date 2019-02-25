//
//  hog.hpp
//  _image
//
//  Created by 唐宇阳 on 2019/02/21.
//  Copyright © 2019 唐宇阳. All rights reserved.
//

#ifndef HOG_HPP
#define HOG_HPP

#include <vector>
#include "image.hpp"

namespace hog {
    const double PI=3.14159265;
    
    class HOGFeature{
    private:
        //typedef std::vector<std::vector<std::vector<double>>> Hist;
        static int LUT[9];
        int bins=9;
        int cellSize=8;
        int blockSize=16;
        int winWidth=64;
        int winHeight=128;
        int cellHistRows;
        int cellHistCols;
        int blockHistRows;
        int blockHistCols;
        int blockHistSize;
        int blockStride=8;
        int hogVectorSize;
        img::Mat<double> magnitude;
        img::Mat<double> angle;
        img::Mat<double> cellHist;
        img::Mat<double> blockHist;
        //Hist cellHist;
        //Hist blockHist;
        std::vector<double> hogVector;
        
        void initial();
        void computeGradient(const img::Mat<img::uchar> &img);
        void assignGradientMagnitude(img::Mat<img::uchar> &img);
        void computeCellHistogram(int yWin, int xWin);
        void normalizeBlockHistogram();
    public:
        HOGFeature() { initial();}
        ~HOGFeature() { std::cout<<"debug"<<std::endl;}
        void processing(img::Mat<img::uchar> &img, int type=0);
        void computeHOGFeature(int xWin, int yWin);
        void save(const std::string &filename);
    };
    
    inline void HOGFeature::processing(img::Mat<img::uchar> &img, int flag)
    {
        computeGradient(img);
        if(flag) assignGradientMagnitude(img);
    }
    
    inline void HOGFeature::assignGradientMagnitude(img::Mat<img::uchar> &img)
    {
        int _size=img.rows*img.cols;
        for(int i=0; i<_size; i++) img.data[i]=magnitude.data[i];
    }
}
#endif /* HOG_HPP */
