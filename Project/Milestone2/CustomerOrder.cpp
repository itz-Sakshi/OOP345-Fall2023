// Name: Sakshi Sakshi
// Seneca Student ID: 112602222
// Seneca email: ssakshi7@myseneca.ca
// Date of completion: 18 November, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"
#include "Utilities.h"
#include "Station.h"

namespace sdds
{
	size_t CustomerOrder::m_widthField = 0; // Initialization of the maximum width of a field, used for display purposes.

	CustomerOrder::CustomerOrder()
	{
		m_name = {};
		m_product = {};
		m_cntItem = 0;
		m_lstItem = nullptr;
	}

	CustomerOrder::CustomerOrder(const std::string& str) : CustomerOrder()
	{
		Utilities utils;
		bool more = true;
		size_t next_pos = 0;
		size_t pos;

		m_name = utils.extractToken(str, next_pos, more);
		if (more)
		{
			m_product = utils.extractToken(str, next_pos, more);
		}
		while (more)
		{
			if (m_cntItem == 0)
			{
				pos = next_pos;
			}
			utils.extractToken(str, next_pos, more);
			m_cntItem++;
		}

		m_lstItem = new Item * [m_cntItem];
		more = true;
		for (size_t i = 0; i < m_cntItem && more; i++)
		{
			m_lstItem[i] = new Item(utils.extractToken(str, pos, more));
		}

		if (CustomerOrder::m_widthField < utils.getFieldWidth())
		{
			CustomerOrder::m_widthField = utils.getFieldWidth();
		}
	}
	// The copy constructor should throw an exception if called
	CustomerOrder::CustomerOrder(const CustomerOrder& c)
	{
		throw "Copy Constructor is DELETED";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& c) noexcept
	{
		*this = std::move(c);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& c) noexcept
	{
		if (this != &c)
		{
			for (size_t i = 0; i < m_cntItem; i++)
			{
				delete m_lstItem[i];
			}
			delete[] m_lstItem;
			this->m_name = c.m_name;
			this->m_product = c.m_product;
			this->m_cntItem = c.m_cntItem;
			this->m_lstItem = c.m_lstItem;
			c.m_name = {};
			c.m_product = {};
			c.m_cntItem = 0;
			c.m_lstItem = nullptr;
		}

		return *this;
	}

	bool CustomerOrder::isOrderFilled() const
	{
		bool result = true;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (!isItemFilled(m_lstItem[i]->m_itemName))
			{
				result = false;
			}
		}

		return result;
	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool result = true;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName)
				result = m_lstItem[i]->m_isFilled;
		}
		return result;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		bool breakCheck = false;
		for (size_t i = 0; i < m_cntItem && !breakCheck; i++)
		{
			if ((m_lstItem[i]->m_itemName == station.getItemName()) && station.getQuantity() >= 1)
			{
				breakCheck = true;
				m_lstItem[i]->m_isFilled = true;
				station.updateQuantity();
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				os << "    Filled " << this->m_name << ", "
					<< this->m_product
					<< " [" << m_lstItem[i]->m_itemName << "]"
					<< std::endl;
			}
			// if the order contains items handled but unfilled, and the inventory is empty, 
			//this function prints the message     Unable to fill NAME, PRODUCT [ITEM_NAME].
			else if ((m_lstItem[i]->m_itemName == station.getItemName()) && (station.getQuantity() == 0) && !m_lstItem[i]->m_isFilled)
			{
				os << "   Unable to fill " << this->m_name << ", "
					<< this->m_product
					<< " [" << m_lstItem[i]->m_itemName << "]"
					<< std::endl;
			}
		}
	}
	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << std::endl;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			os << std::setw(6) << std::setfill('0') << "[" << m_lstItem[i]->m_serialNumber << "] ";
			os << std::setfill(' ');
			os << std::left << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
			os << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
		}
	}
	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}
}