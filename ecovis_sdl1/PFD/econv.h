void EndianConvert(char *byte,int numbytes)
{
	static int i;
	static unsigned char temp_buffer[10];

	switch (numbytes)
	{
	case 0:
		break; //hinzugefügt R.W.
	case 1:
		break;
	case 2:
		*(short *)temp_buffer=*(short *)byte;
		byte[0]=temp_buffer[1];
		byte[1]=temp_buffer[0];
		break;

	case 4:
		*(int *)temp_buffer=*(int *)byte;
		byte[0]=temp_buffer[3];
		byte[1]=temp_buffer[2];
		byte[2]=temp_buffer[1];
		byte[3]=temp_buffer[0];
		break;

	case 8:
		*(double *)temp_buffer=*(double *)byte;
		byte[0]=temp_buffer[7];
		byte[1]=temp_buffer[6];  		
		byte[2]=temp_buffer[5];
		byte[3]=temp_buffer[4];  		
		byte[4]=temp_buffer[3];
		byte[5]=temp_buffer[2];  		
		byte[6]=temp_buffer[1];
		byte[7]=temp_buffer[0];  		
		break;

	default:
		if (numbytes>10)
			return;
		memcpy(temp_buffer,byte,numbytes);
		for (i=0;i<numbytes;i++)
			*((unsigned char *)byte+i)=temp_buffer[numbytes-1-i];
	}
}
