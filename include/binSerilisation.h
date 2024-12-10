#pragma once

void serialize(const Array &array, const string &filename);
void deserialize(Array &array, const string &filename);

void serialize(SingleList &list, const string &filename);
void deserialize(SingleList &list, const string &filename);

void serialize(Queue &queue, const string &filename);
void deserialize(Queue &queue, const string &filename);

void serialize(Stack &stack, const string &filename);
void deserialize(Stack &stack, const string &filename);

void serialize(DoubleList &list, const string &filename);
void deserialize(DoubleList &list, const string &filename);



