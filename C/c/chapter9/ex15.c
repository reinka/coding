double medion(double x, double y, double z)
{
   double median;

   if(x<=y)
	if (y<=z) median= y;
	else if(x<=z) median = z;
	else median = x;
   else{
   	if(z<=y) median = y;
   	else if(x<=z) median = x;
   	else median = z;
   }

   return median;
}
