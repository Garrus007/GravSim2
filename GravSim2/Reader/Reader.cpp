#include "Reader.h"


Reader::Reader()
{
}

Reader::Reader(const char * filename) :stream(filename, std::ios::in | std::ios::binary)
{
	if (!stream)
		throw std::string("Unable to open file \"") + std::string(filename) + std::string("\"");

	stream.read((char*)&pointsCount, sizeof(pointsCount));
}


Reader::~Reader()
{
}

/*!
* \brief ��������� ����
*/
unsigned int Reader::Open(const char * filename)
{
	stream.open(filename, std::ios::in | std::ios::binary);

	if (!stream)
		throw std::string("Unable to open file \"") + std::string(filename) + std::string("\"");

	if (stream.eof())
		throw std::string("Empty input file");

	stream.read((char*)&pointsCount, sizeof(pointsCount));
	return pointsCount;
}

/*!
* \brief ���������� ���������� ����� � �����
*/
unsigned int Reader::GetPointsCount()
{
	return pointsCount;
}

void Reader::Close()
{
}

/*!
* \brief ��������� ���� ���� �� �����
*/
Frame*  Reader::ReadFrame()
{
	Frame* frame = new Frame();
	frame->Points = new Point[pointsCount];

	if (!ReadFrame(frame))
		return nullptr;
	
	return frame;
}

/*!
* \brief ��������� ���� ���� �� �����
*        � ���������� ��� �� ���������
*		  �� Frame.
*
* ��������:
* ���������, ��� �� FRAME ������� �����
* POINTS ������������ �������
*/
bool Reader::ReadFrame(Frame * frame)
{
	if (stream.eof())
		return false;

	stream.read((char*)&frame->Dt, sizeof(frame->Dt));
	frame->Count = pointsCount;
	stream.read((char*)frame->Points, sizeof(Point)*pointsCount);

	return true;
}
