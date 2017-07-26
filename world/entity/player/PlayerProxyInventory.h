#pragma once

#include <memory>

class Inventory;
class ItemInstance;
class HudContainerManagerModel;
class ContainerContentChangeListener;
class ListTag;
enum class ContainerID;

class PlayerInventoryProxy {

public:

	struct SelectedSlot {
		ContainerID container;
		int slot;
	};
	struct LinkedSlot {
		int from, to;
	};


	virtual void* containerSizeChanged(int);
	virtual ~PlayerInventoryProxy();

	PlayerInventoryProxy(std::unique_ptr<Inventory, std::default_delete<Inventory>>);

	void init(std::weak_ptr<HudContainerManagerModel>);
	void addListener(ContainerContentChangeListener*);
	void removeListener(ContainerContentChangeListener*);

	void setContainerChanged(int);
	void selectSlot(int, ContainerID);

	bool linkSlot(int, int);
	void unlinkSlot(int);
	void linkEmptySlot(int);
	ItemInstance* getLinked(int) const;
	int getLinkedSlot(int) const;
	int getLinkedSlotForItem(int) const;
	int getLinkedSlotForExactItem(ItemInstance const&) const;
	std::vector<LinkedSlot> getLinkedSlots() const;
	int getLinkedSlotsCount() const;

	bool add(ItemInstance&, bool);
	bool canAdd(ItemInstance const&) const;
	void removeItem(int, int, ContainerID);
	int getSlotWithItem(ItemInstance const&, bool, bool) const;
	void moveToSelectionSlot(int, int);
	int getEmptySlotsCount() const;
	void* getSlots();
	void* getSlotCopies(ContainerID) const;
	void* _getHudContainer() const;
	void setContainerSize(int, ContainerID);
	int getContainerSize(ContainerID) const;
	bool hasResource(int);
	bool _hasFixedInventoryResource(int);
	bool removeResource(int);
	bool removeResource(ItemInstance const&);
	int removeResource(ItemInstance const&, bool);
	void swapSlots(int, int);
	void clearSlot(int, ContainerID);
	void clearInventory(int);
	void clearInventoryWithDefault(bool);
	void replaceSlot(int, ItemInstance const&);
	void* load(ListTag const&);
	void* save();
	void dropSlot(int, bool, bool, ContainerID, bool);
	void dropAll(bool);
	void tick();
	void setItem(int, ItemInstance const&, ContainerID);
	ItemInstance getItem(int, ContainerID) const;
	void* _getHudContainerManagerModel();
	void* _getInventoryContainer();
	void* _getCurrentSlotCount();
	SelectedSlot getSelectedSlot() const;
	ContainerID getSelectedContainerId();
	void moveToSelectedSlot(int, ContainerID);
	ItemInstance* getSelectedItem();
	void selectFixedInventorySlot(int);
	int getFixedInventorySlotCount() const;
	void* getAllContainerIds();

};
