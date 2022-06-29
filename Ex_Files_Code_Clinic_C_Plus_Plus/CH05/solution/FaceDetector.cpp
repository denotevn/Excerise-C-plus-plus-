/**
 * FaceDetector.cpp by Olivia Stone for Code Clinic: C++
 **/

#include "FaceDetector.hpp"

/* declaration for function in giflib_to_opencv.cpp to convert
   gif images to a image file that can be used in opencv */
cv::Mat imread_gif(const std::string& filename, const int flags);

int FaceDetector::loadCascade()
{
    if (!faceHaarCascade_.load(HAAR_CASCADE_PATH))
    {
        std::cerr << "ERROR: Failed to load Haar Cascade from " << HAAR_CASCADE_PATH << std::endl;
        return -1; // failure
    }
    return 0; // success
}

int FaceDetector::loadImage(std::string imagePath)
{
    imagePath_ = imagePath;
    
    std::string fileExtension;
    if (imagePath.find_last_of(".") != std::string::npos)
    {
        fileExtension = imagePath.substr(imagePath.find_last_of(".")+1);
        for(unsigned int i = 0; i < fileExtension.length(); ++i)
        {
            fileExtension[i] = tolower(fileExtension[i]);
        }
    }

    // use correct read function based on file extension
    if ((fileExtension == "jpg") || (fileExtension == "jpeg"))
    {
        image_ = cv::imread(imagePath);
    }
    else if (fileExtension == "png")
    {
        image_ = cv::imread(imagePath);
    }
    else if (fileExtension == "gif")
    {
        /* use gif_lib to load gif file */
        int error = 0;
        GifFileType* gifFile = DGifOpenFileName(imagePath.c_str(), &error); // open gif

        if (!gifFile || (error != 0))
        {
            std::cerr << "ERROR: Could not open gif - " << GifErrorString(error) << std::endl;
            return -2; // failure
        }

        if (DGifSlurp(gifFile) != GIF_OK) // read gif contents into memory structure
        {
            std::cerr << "ERROR: Could not load gif - " << GifErrorString(error) << std::endl;
            return -2; // failure
        }

        const int width = gifFile->Image.Width;
        const int height = gifFile->Image.Height;
        image_ = cv::Mat(cv::Size(width, height), CV_8UC3);

        GifColorType *colorMap = gifFile->SColorMap->Colors;
        SavedImage *img = &gifFile->SavedImages[0];

        auto *ptr = image_.ptr<cv::Vec3b>();
		for (int i = 0; i < width * height; i++, ptr++) {
			const GifColorType &color = colorMap[img->RasterBits[i]];
			*ptr = cv::Vec3b(color.Red, color.Green, color.Blue);
		}
		cvtColor(image_, image_, CV_RGB2BGR);

        DGifCloseFile(gifFile, &error);
    }
    else
    {
        std::cerr << "ERROR: Unrecognized file extension on " << imagePath << std::endl;
        return -1; // failure
    }
    
    // verify that the image was loaded
    if (image_.empty())
    {
        std::cerr << "ERROR: Failed to load image file " << imagePath << std::endl;
        return -2; // failure
    }

    return 0; // success!
}

int FaceDetector::detectFaces()
{
    if (image_.empty())
    {
        std::cerr << "ERROR: Cannot detect faces; image_ not loaded" << std::endl;
        return -1; // failure
    }

    // convert image to grayscale
    cv::Mat imageGrayScale;
    cv::cvtColor(image_, imageGrayScale, cv::COLOR_BGR2GRAY);
	cv::equalizeHist(imageGrayScale, imageGrayScale);

    // use haar cascade to detect faces
    faceHaarCascade_.detectMultiScale(imageGrayScale, faces_, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(250, 250));

    return faces_.size(); // number of faces detected
}

void FaceDetector::displayImage()
{
    if (image_.empty())
    {
        std::cerr << "ERROR: Cannot display image_; image_ not loaded" << std::endl;
        return; // failure
    }

    for (int i = 0; i < faces_.size(); i++)
	{
		cv::Point center(faces_[i].x + faces_[i].width / 2, faces_[i].y + faces_[i].height / 2);
		cv::ellipse(image_, center, cv::Size(faces_[i].width / 2, faces_[i].height / 2), 0, 0, 360, cv::Scalar(0, 255, 0), 10, 8, 0);
	}

    // scale image to fit within 1280x720 window
    shrinkImage(1280, 720);

    // create a window for display
	cv::namedWindow("Face Detector", cv::WINDOW_AUTOSIZE); 
	cv::imshow("Face Detector", image_);
    cv::waitKey(0);
}

void FaceDetector::saveJSON()
{
    if (imagePath_.empty())
    {
        std::cerr << "ERROR: Cannot save JSON; imagePath_ not available" << std::endl;
        return; // failure
    }

    Json::Value result;
	Json::StreamWriterBuilder builder;
	std::ofstream outFile;

    // populate the JSON fields
	result["countFaces"] = faces_.size();
    char absolutePath [PATH_MAX + 1];
    result["imageLocation"] = realpath(imagePath_.c_str(), absolutePath);

    // create output file in same directory as image
    std::string outFileName = imagePath_ + ".json";
	outFile.open(outFileName);
	builder.newStreamWriter()->write(result, &outFile);
	outFile.close();
    
    std::cout << "Saved " << outFileName << std::endl;
}

void FaceDetector::shrinkImage(int maxWidth, int maxHeight)
{
    if (image_.empty())
    {
        std::cerr << "ERROR: Cannot scale image_; image_ not loaded" << std::endl;
        return; // failure
    }

    // scale image_ to fit within maxWidth x maxHeight
    cv::Size s = image_.size();
    if ((s.width/s.height) > (maxWidth/maxHeight)) // scale based on width
    {
        cv::resize(image_, image_,
                   cv::Size(maxWidth, (s.height * maxWidth / s.width)));
    }
    else // scale based on height
    {
        cv::resize(image_, image_,
                   cv::Size((s.width * maxHeight / s.height), maxHeight));
    }
}