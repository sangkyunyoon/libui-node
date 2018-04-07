#include <string>
#include "../ui.h"
#include "nbind/api.h"
#include "includes/control.h"

class UiMultilineEntry : public UiControl {
	DEFINE_EVENT(onChanged)

  public:
	UiMultilineEntry();
	DEFINE_CONTROL_METHODS()
	void setText(std::string text);
	std::string getText();
	void setReadOnly(bool readOnly);
	bool getReadOnly();
	void append(std::string text);
};

UiMultilineEntry::UiMultilineEntry()
	: UiControl(uiControl(uiNewNonWrappingMultilineEntry())) {}

INHERITS_CONTROL_METHODS(UiMultilineEntry)

IMPLEMENT_EVENT(UiMultilineEntry, uiMultilineEntry, onChanged,
				uiMultilineEntryOnChanged)

void UiMultilineEntry::setText(std::string text) {
	uiMultilineEntrySetText(uiMultilineEntry(getHandle()), text.c_str());
	if (onChangedCallback != NULL) {
		(*onChangedCallback)();
	}
}

std::string UiMultilineEntry::getText() {
	char *char_ptr = uiMultilineEntryText(uiMultilineEntry(getHandle()));
	std::string s(char_ptr);
	uiFreeText(char_ptr);
	return s;
}

void UiMultilineEntry::setReadOnly(bool readOnly) {
	uiMultilineEntrySetReadOnly(uiMultilineEntry(getHandle()), readOnly);
}

bool UiMultilineEntry::getReadOnly() {
	return uiMultilineEntryReadOnly(uiMultilineEntry(getHandle()));
}

void UiMultilineEntry::append(std::string text) {
	uiMultilineEntryAppend(uiMultilineEntry(getHandle()), text.c_str());
}

NBIND_CLASS(UiMultilineEntry) {
	construct<>();
	DECLARE_CHILD_CONTROL_METHODS()
	getset(getText, setText);
	getset(getReadOnly, setReadOnly);
	method(getText);
	method(setText);
	method(getReadOnly);
	method(setReadOnly);
	method(append);
	method(onChanged);
}
