function varargout = myVirtualCam(varargin)
% MYVIRTUALCAM MATLAB code for myVirtualCam.fig
%      MYVIRTUALCAM, by itself, creates a new MYVIRTUALCAM or raises the existing
%      singleton*.
%
%      H = MYVIRTUALCAM returns the handle to a new MYVIRTUALCAM or the handle to
%      the existing singleton*.
%
%      MYVIRTUALCAM('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in MYVIRTUALCAM.M with the given input arguments.
%
%      MYVIRTUALCAM('Property','Value',...) creates a new MYVIRTUALCAM or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before myVirtualCam_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to myVirtualCam_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help myVirtualCam

% Last Modified by GUIDE v2.5 16-Apr-2019 13:52:35

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @myVirtualCam_OpeningFcn, ...
                   'gui_OutputFcn',  @myVirtualCam_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before myVirtualCam is made visible.
function myVirtualCam_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to myVirtualCam (see VARARGIN)
X = pcread('model.ply');
axes(handles.axes1);
pcshow(X);
hold on;
t = [0 0 0]';
R = eye(3,3);
cam = plotCamera('Location',t,'Orientation',R,'Size',50);
handles.X = X;
% Choose default command line output for myVirtualCam
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes myVirtualCam wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = myVirtualCam_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function f_x_Callback(hObject, eventdata, handles)
% hObject    handle to f_x (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of f_x as text
%        str2double(get(hObject,'String')) returns contents of f_x as a double


% --- Executes during object creation, after setting all properties.
function f_x_CreateFcn(hObject, eventdata, handles)
% hObject    handle to f_x (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function f_y_Callback(hObject, eventdata, handles)
% hObject    handle to f_y (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of f_y as text
%        str2double(get(hObject,'String')) returns contents of f_y as a double


% --- Executes during object creation, after setting all properties.
function f_y_CreateFcn(hObject, eventdata, handles)
% hObject    handle to f_y (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function c_x_Callback(hObject, eventdata, handles)
% hObject    handle to c_x (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of c_x as text
%        str2double(get(hObject,'String')) returns contents of c_x as a double


% --- Executes during object creation, after setting all properties.
function c_x_CreateFcn(hObject, eventdata, handles)
% hObject    handle to c_x (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function c_y_Callback(hObject, eventdata, handles)
% hObject    handle to c_y (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of c_y as text
%        str2double(get(hObject,'String')) returns contents of c_y as a double


% --- Executes during object creation, after setting all properties.
function c_y_CreateFcn(hObject, eventdata, handles)
% hObject    handle to c_y (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
contents = cellstr(get(handles.f_x,'String')); % 获取下拉菜单信息
f_x = str2double(contents{get(hObject,'Value')}); % 返回所选项
contents = cellstr(get(handles.f_y,'String')); % 获取下拉菜单信息
f_y = str2double(contents{get(hObject,'Value')}); % 返回所选项        
contents = cellstr(get(handles.c_x,'String')); % 获取下拉菜单信息
c_x = str2double(contents{get(hObject,'Value')}); % 返回所选项
contents = cellstr(get(handles.c_y,'String')); % 获取下拉菜单信息
c_y = str2double(contents{get(hObject,'Value')}); % 返回所选项

X = handles.X;
K = [f_x 0 c_x;0 f_y c_y;0 0 1];
S = double(X.Location);
m = K*S';
mx = (m(1,:)./m(3,:))';
my = (m(2,:)./m(3,:))';
C = im2double(X.Color);
axes(handles.axes2);
img = zeros(100,100,3);
dist = ones(100,100,3)*1000; %距离矩阵初始化为很大的数
ctx = round(50-(max(mx)+min(mx))/2);
cty = round(50-(max(my)+min(my))/2);

for i = 1:53215
    try
        %选择投影点中距离最近的值
        d = (my(i)-round(my(i)))^2+(mx(i)-round(mx(i)))^2;
        if dist(round(my(i)+ctx),round(mx(i)+cty))>d
            img(round(my(i)+ctx),round(mx(i)+cty),:) = C(i); % 使图像处于图片中央
            dist(round(my(i)+ctx),round(mx(i)+cty)) = d;
        end
    catch
    end
end
imshow(img)
