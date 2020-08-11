double* RotationImage(BYTE* Buffer, int Width, int Height, double radius)//gray scale image
{
	double* newbuf = new double[Width * Height];
	int tep, ntep;
	int nrow, ncol;
	int x, y, nx, ny;
	for (int row = 0; row < Height; row++)
	{
		for (int col = 0; col < Width; col++)
		{
			tep = row * Width + col;
			x = col - (Width / 2);
			y = (Height / 2) - row;
			nx = (x * cos(radius*PI/180)) - (y * sin(radius*PI/180));
			ny = (x * sin(radius*PI/180)) + (y * cos(radius*PI/180));
			ncol = nx + (Width / 2);
			nrow = (Height / 2) - ny;
			ntep = nrow * Width + ncol;
			newbuf[ntep] = Buffer[tep];
		}
	}
	return newbuf;
}
