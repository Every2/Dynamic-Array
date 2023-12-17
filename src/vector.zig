const std = @import("std");

const Allocator = std.mem.Allocator;

pub fn DynamicArray(comptime T: type, Allocator: type) type {
    return struct {
        items: ?*T,
        len: usize,
        cap: usize,
        allocator: *Allocator,
    };
}

pub fn initDynamicArray(comptime T: type, Allocator: type, allocator: *Allocator) DynamicArray(T, Allocator) {
    return DynamicArray(T, Allocator){
        .items = null,
        .len = 0,
        .cap = 0,
        .allocator = allocator,
    };
}

pub fn push(comptime T: type, Allocator: type, arr: *DynamicArray(T, Allocator), value: T) void {
    const new_len = arr.len + 1;
    if (new_len > arr.cap) {
        const new_cap = if (arr.cap == 0) 1 else arr.cap * 2;
        const new_items = try allocator.alloc(T, new_cap);
        if (new_items == null) {
            std.debug.print("Failed to allocate memory\n", .{});
            return;
        }
        if (arr.items != null) {
            std.debug.print("Copying elements to new array\n", .{});
            std.mem.copyNonOverlapping(T, new_items, arr.items, arr.len);
            try allocator.free(arr.items);
        }
        arr.items = new_items;
        arr.cap = new_cap;
    }
    arr.items[new_len - 1] = value;
    arr.len = new_len;
}

pub fn deinit(comptime T: type, Allocator: type, arr: *DynamicArray(T, Allocator)) void {
    if (arr.items != null) {
        try arr.allocator.free(arr.items);
    }
}

pub fn main() void {
    const allocator = std.heap.page_allocator;
    var array = initDynamicArray(i32, typeof(allocator), &allocator);
    
    push(i32, typeof(allocator), &array, 42);
    push(i32, typeof(allocator), &array, 17);
    push(i32, typeof(allocator), &array, 99);
    
    std.debug.print("Array length: {}, capacity: {}\n", .{array.len, array.cap});
    
    for (array.items) |i| {
        std.debug.print("array[{}] = {}\n", .{i});
    }
    
    deinit(i32, typeof(allocator), &array);
}