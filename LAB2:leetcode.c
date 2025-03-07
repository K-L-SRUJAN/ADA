


typedef struct {
    int *prices;
    int *spans;
    int top;
} StockSpanner;

StockSpanner* stockSpannerCreate() {
    StockSpanner* obj = (StockSpanner*)malloc(sizeof(StockSpanner));
    obj->prices = (int*)malloc(100 * sizeof(int));
    obj->spans = (int*)malloc(100 * sizeof(int));
    obj->top = -1;
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int span = 1;
    while (obj->top != -1 && obj->prices[obj->top] <= price) {
        obj->top--;
        span += obj->spans[obj->top + 1];
    }
    obj->top++;
    obj->prices[obj->top] = price;
    obj->spans[obj->top] = span;
    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->prices);
    free(obj->spans);
    free(obj);
}


/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
*/
