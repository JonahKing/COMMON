
void sort(int* array,unsigned int size_of_array)
{
	int i,j,temp;
	for(i = 0;i < size_of_array;i++)
	{
		for(j = i+1;j<size_of_array;j++)
		{
			if(array[i] < array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}
