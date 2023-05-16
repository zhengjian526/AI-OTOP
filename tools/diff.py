from fileinput import filename
import numpy as np
import os

def load_and_diff(hwfname, swname, dtype=np.float32, hwshape=None, swshape=None):
    swname = swname.replace('/', '_') + '.bin'
    hwfname = hwfname.replace('/', '_') + '.bin'
    hw_path = '../build/tests/res_data'

    sw_path = '../build/tests/res_data'

    print(hw_path)
    print(sw_path)
    print(dtype)
    hw = np.fromfile(os.path.join(hw_path, hwfname), dtype)
    sw = np.fromfile(os.path.join(sw_path, swname), dtype)
    hw = hw.reshape(hwshape)
    sw = sw.reshape(swshape)

    # if hw.size == sw.size:
    #     print(np.max(np.abs(hw - sw)))
    return hw, sw


def Diff():
    h, s = load_and_diff("sigmoid_native","sigmoid_x86", 
                        dtype=np.float32,
                        hwshape=[10, 100, 100],swshape=[10, 100, 100])
    # h, s = load_and_diff("from_ast_59_Reshape__15_TypeCast_0_loop_idx_0","unknown_273_split_26_loop_idx_0", dtype=np.uint8,shape=[256])
    min_size = 0;
    s_copy = s.copy()
    if h.size != s.size:
        print("======%s and %s shape not equal ======",h.shape, s.shape)
        min_size = min(h.size,s.size)
        h = h.reshape(-1)[0:min_size]
        s = s.reshape(-1)[0:min_size]
    h = h.astype(np.float32)
    s = s.astype(np.float32)
    s_copy = s_copy.astype(np.float32)
    print(s_copy.shape)

    print("sum h: ",np.sum(h))
    print("sum s: ",np.sum(s))
    # h = h.reshape(-1, h.size)
    # s = s.reshape(-1, s.size)
    print(30*"-")
    print("shape size: %d, h_max: %f, h_min: %f, s_max: %f, s_min: %f,\nmean_err: %f, max_err: %f, large than N : %f"
        %(h.size, np.max(h), np.min(h),np.max(s), np.min(s),float(np.mean(np.abs(h - s))),float(np.max(np.abs(h - s))), np.sum(np.abs(h - s) > 10)))
    print(30*"-")
    print(h.reshape(-1)[0:100])
    print(30*"--")
    # print(s.reshape(-1)[:72])
    # print(30*"--")
    print(s_copy.reshape(-1)[0:100])
    # print(np.sort(h,0)[:200])
    print("最大误差下标: ",np.argmax(h-s))

def PrintElement():
    root_path = '/workspace/CodeWork/rbrt/torch_siamfc/backbone_b0/bins/sim/simdata_new'
    file_name = 'ChannelF2L_transpose_1_TypeCast_3'
    # file_name = 'nms_31_loop_idx_0'
    file_name = file_name.replace('/', '_')
    file_name = os.path.join(root_path, file_name) + '.bin'
    arr = np.fromfile(file_name, dtype = np.float32)
    print(arr.shape)
    print(30*"--")
    print(arr.reshape(-1)[:50])

def TransNumpyArrToBin():
    file_name = '/workspace/CodeWork/rbrt/SiamfcTestCar1/kernel_input.npy'
    arr = np.load(file_name)
    # print(arr)
    print(arr.shape)
    print(arr.dtype)
    out_dir = '/workspace/CodeWork/rbrt/SiamfcTestCar1/kernel_input/'
    filter = 1
    for i in range(int(arr.shape[0]/filter)):
        temp_arr = arr[i*filter:(i+1)*filter]
        temp_arr.tofile(out_dir + str(i) + '.bin')
    
if __name__ == '__main__':
    print('================================= show diff ==============================================')
    Diff()
    # print('================================= show element ==============================================')
    # PrintElement()
    # TransNumpyArrToBin()

    