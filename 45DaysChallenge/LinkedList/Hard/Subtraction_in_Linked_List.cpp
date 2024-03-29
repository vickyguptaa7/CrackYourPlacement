void addNodeToTail(Node *&head, Node *&tail, Node *&node)
{
    if (!head)
    {
        tail = node;
        head = node;
        node = node->next;
        tail->next = nullptr;
        return;
    }
    tail->next = node;
    tail = tail->next;
    node = node->next;
    tail->next = nullptr;
}

int listLength(Node *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

bool isFirstGreater(Node *head1, Node *head2)
{
    while (head1 && head1->data == head2->data)
    {
        head1 = head1->next;
        head2 = head2->next;
    }
    if (!head1)
        return true;
    return head1->data > head2->data;
}

Node *reverseList(Node *head)
{
    Node *curr = head, *prev = nullptr, *next = nullptr;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *removeTrailingZero(Node *head)
{
    int zc = 0, llen = listLength(head);
    Node *curr = head;
    while (curr && curr->data == 0)
    {
        zc++;
        curr = curr->next;
    }
    if (zc == llen)
    {
        return new Node(0);
    }
    return curr;
}

Node *subLinkedList(Node *l1, Node *l2)
{
    l1 = removeTrailingZero(l1);
    l2 = removeTrailingZero(l2);

    int len1 = listLength(l1);
    int len2 = listLength(l2);

    if (len1 < len2)
    {
        return subLinkedList(l2, l1);
    }

    if (len1 == len2 && !isFirstGreater(l1, l2))
    {
        return subLinkedList(l2, l1);
    }
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    int borrow = 0;
    Node *head = nullptr, *tail = nullptr;
    while (l1 || l2)
    {
        int num1 = 0;
        if (l1)
        {
            num1 = l1->data;
            l1 = l1->next;
        }
        int num2 = 0;
        if (l2)
        {
            num2 = l2->data;
            l2 = l2->next;
        }
        int diff = num1 - num2 - borrow;
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        Node *node = new Node(diff);
        addNodeToTail(head, tail, node);
    }
    head = reverseList(head);

    return removeTrailingZero(head);
}