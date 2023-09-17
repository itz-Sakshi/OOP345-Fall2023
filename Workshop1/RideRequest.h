#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H

extern double g_taxrate;
extern double g_discount;
namespace sdds
{
	
	class RideRequest
	{
	public:
		RideRequest();
		~RideRequest();
		void read(std::istream& in);
		void display();
                RideRequest& operator=(const RideRequest& other);
                RideRequest(const RideRequest& other);


	private:
		static int counter;
		char customerName[10];
		char* rideDetail;
		double price;
		bool hasDiscount;

	};

	
}

#endif
