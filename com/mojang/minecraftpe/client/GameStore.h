#pragma once

// 0.14.0

#include <string>
#include <vector>

class PurchaserCache;
class Product;
class PurchaseInfo;

class GameStore {
public:
	void* playStore; // 4
	PurchaserCache* purchaser; // 8

public:
	GameStore();
	virtual ~GameStore();
	virtual void onStoreInitialized(bool); 
	virtual void onQueryProductsSuccess(const std::vector<Product>&);
	virtual void onQueryProductsFail();
	virtual void onPurchaseSuccessful(const std::string&);
	virtual void onPurchaseCanceled(const std::string&);
	virtual void onPurchaseFailed(const std::string&);
	virtual void onQueryPurchasesSuccess(const std::vector<PurchaseInfo>&);
	virtual void onQueryPurchasesFail();
	virtual void onAppPurchaseSuccess();
	virtual void onAppPurchaseFailed();
	virtual void onAppPurchaseCanceled();
	bool allowsQueryPurchasesOnStartup() const;
	void getStoreId() const;
	bool isAvailable() const;
	bool isTrial() const;
};
