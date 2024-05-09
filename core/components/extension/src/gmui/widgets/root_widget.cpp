#include "gmui/widgets/root_widget.h"

using namespace godot;

RootWidget::RootWidget(Widget *child) {
	_child = child;
}

RootWidget::~RootWidget() {
}
void RootWidget::set_child(Widget *child) {
	_child = child;
}

Widget *RootWidget::get_child() {
	return _child;
}

Element *RootWidget::attach(BuildOwner *owner, Element *element) {
	if (element) {
		return element;
	} else {
		return attach(owner);
	}
}

Element *RootWidget::attach(BuildOwner *owner) {
	Element *element = create_element();
	DEV_ASSERT(element);
	element->mount();
	return element;
}

Element *RootWidget::create_element() {
	return new RootElement(this);
}

void RootWidget::_bind_methods() {
}
