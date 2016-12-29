#ifndef __READER_H__
#define __READER_H__

#include <fstream>
#include "Frame.h"

class Reader
{
public:
	Reader();
	Reader(const char* filename);
	~Reader();

	/*! 
	 * \brief ��������� ����
	 */
	unsigned int Open(const char* filename);

	/*!
	 * \brief ���������� ���������� ����� � �����
	 */
	unsigned int GetPointsCount();
	void Close();

	/*!
	 * \brief ��������� ���� ���� �� ����� � 
	 *        �������� ������ ��� ������ ��� ������
	 *	 	  Frame
	 */
	Frame* ReadFrame();

	/*!
	 * \brief ��������� ���� ���� �� �����
	 *        � ���������� ��� �� ���������
	 *		  �� Frame. 
	 *
	 * ��������:
	 * ���������, ��� �� FRAME ������� �����
     * POINTS ������������ �������
 	 */
	bool ReadFrame(Frame* frame);

private:

	std::ifstream stream;
	unsigned int pointsCount;
};

#endif