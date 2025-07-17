struct ListNode {
    int data;
    ListNode* next;
    
    ListNode(int val) : data(val), next(nullptr) {}
};

ListNode* createLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

void deleteLinkedList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

ListNode* findMiddle(ListNode* head) {
    if (head == nullptr) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;

    while (current != nullptr) {
        ListNode* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev; // New head of the reversed list
}
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    ListNode* mergedHead = nullptr;

    if (l1->data < l2->data) {
        mergedHead = l1;
        l1 = l1->next;
    } else {
        mergedHead = l2;
        l2 = l2->next;
    }

    ListNode* current = mergedHead;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data < l2->data) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    if (l1 != nullptr) {
        current->next = l1;
    } else {
        current->next = l2;
    }

    return mergedHead;
}
ListNode* mergeKLists(ListNode* lists[], int k) {
    if (k == 0) return nullptr;

    ListNode* mergedList = lists[0];
    for (int i = 1; i < k; ++i) {
        mergedList = mergeTwoLists(mergedList, lists[i]);
    }

    return mergedList;
}
ListNode* removeDuplicates(ListNode* head) {
    if (head == nullptr) return nullptr;

    ListNode* current = head;
    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            ListNode* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            current = current->next;
        }
    }

    return head;
}
ListNode* partitionList(ListNode* head, int x) {
    ListNode* lessHead = new ListNode(0);
    ListNode* greaterHead = new ListNode(0);
    ListNode* less = lessHead;
    ListNode* greater = greaterHead;

    while (head != nullptr) {
        if (head->data < x) {
            less->next = head;
            less = less->next;
        } else {
            greater->next = head;
            greater = greater->next;
        }
        head = head->next;
    }

    greater->next = nullptr; // End the greater list
    less->next = greaterHead->next; // Connect the two lists

    ListNode* newHead = lessHead->next;
    delete lessHead; // Clean up dummy node
    delete greaterHead; // Clean up dummy node

    return newHead;
}
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == nullptr || m >= n) return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;

    for (int i = 1; i < m; ++i) {
        prev = prev->next;
    }

    ListNode* start = prev->next;
    ListNode* then = start->next;

    for (int i = 0; i < n - m; ++i) {
        start->next = then->next;
        then->next = prev->next;
        prev->next = then;
        then = start->next;
    }

    return dummy.next;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry > 0) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }

    return dummy.next; // Return the next node to skip the dummy head
}

ListNode* detectCycle(ListNode* head) {
    if (head == nullptr) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle detected
            ListNode* entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry; // Start of the cycle
        }
    }

    return nullptr; // No cycle
}