#include "inc/sort.h"

/* Χρησιμοποιώντας δύο βοηθητικούς πίνακες L και R, χωρίζουμε τον
δοσμένο πίνακα. Έπειτα, τους συγχωνέυουμε στον δοσμένο πίνακα,
επιλέγοντας κάθε φορά το μικρότερο στοιχείο */
int* merge(int* array, int left, int mid, int right)
{
	int i, j, k = 0;
	int x = mid - left + 1;
	int y = right - mid;
	
	int L[x], R[y];
	
	/* Δημιουργία βοηθητικών πινάκων L (αριστερό μέρος) και 
	R (δεξί μέρος) */
	for (i = 0; i < x; i++)
	{
		L[i] = array[left + i];
	}
	for (j = 0; j < y; j++)
	{
		R[j] = array[mid + j + 1];
	}
	
	/* Συγχώνευση με επιλογή του μικρότερου στοιχείου από τους 
	πίνακες L και R */
	i = 0;
	j = 0;
	k = left;
	
	while (i < x && j < y)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		
		k++;
	}
	
	while (i < x)
	{
		array[k] = L[i];
		i++;
		k++;
	}
	
	while (j < y)
	{
		array[k] = R[j];
		j++;
		k++;
	}
	
	return array;
}

/* Αλγόριθμος διαίρει-και-βασίλευε για merge sort */
void mergesort(int* array, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;/* Εύρεση μέσου του πίνακα */
		mergesort(array, left, mid);		/* Αναδρομικό κάλεσμα για τον
											αριστερό υποπίνακα */
		mergesort(array, mid + 1, right);	/* Αναδρομικό κάλεσμα για τον
											δεξιό υποπίνακα */
		
		merge(array, left, mid, right);		/* Συγχώνευση αριστερού και
											δεξιού υποπίνακα */
	}
}

